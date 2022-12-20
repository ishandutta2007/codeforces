#include <iostream>
using namespace std;

int A[100][100];

int main()
{
	int n,a,b;
	cin >> n >> a >> b;
	int c1 = 0;
	int c2 = 0;
	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
		{
			if((i+j)%2) c1++;
			else c2++;
		}
	int n1 = n/2;
	int n2 = n-(n/2);
	if(n2 <= c2 && n1 <= c1)
	{
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				if((i+j)%2 && n1) cout << 2*(n1--) << ' ';
				else if((i+j)%2==0 && n2) cout << 2*(n2--) - 1 << ' ';
				else cout << 0 << ' ';
			}
			cout << '\n';
		}
	}
	else if(n2 <= c1 && n1 <= c2)
	{
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				if((i+j)%2 && n2) cout << 2*(n2--) - 1<< ' ';
				else if((i+j)%2==0 && n1) cout << 2*(n1--) << ' ';
				else cout << 0 << ' ';
			}
			cout << '\n';	
		}
	}
	else
	{
		cout << -1 << '\n';
		return 0;
	}
}