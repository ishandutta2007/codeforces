#include <iostream>
using namespace std;

int main()
{
	int N,K;
	cin >> N >> K;
	if(K > (N*N+1)/2)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(K && !((i+j)&1))
				{
					cout << "L";
					K--;
				}
				else
					cout << "S";
			}
			cout << endl;
		}
	}
}