#include <iostream>
using namespace std;

int A[100000];

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=30;i>=0;i--)
	{
		int lft = (1<<i)-1;
		int c = 0;
		for(int j=0;j<N;j++)
			if(A[j] & (1<<i))
				lft &= A[j], c++;
		if(lft == 0)
		{
			cout << c << '\n';
			for(int j=0;j<N;j++)
				if(A[j] & (1<<i))
					cout << A[j] << ' ';
			cout << '\n';
			return 0;
		}
	}
}