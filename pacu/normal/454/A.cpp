#include <iostream>
using namespace std;

int main()
{
	int N;
	int i,j;
	cin >> N;
	int s = (N-1)/2;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if((abs(s-i)+abs(s-j))<=s)
				cout << "D";
			else
				cout << "*";
		}
		cout << endl;
	}
}