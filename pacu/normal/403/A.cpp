#include <iostream>
using namespace std;

int con[24][24];

void test(int n,int p)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
			con[i][j] = 0;
	}
	for(int i=0;i<n;i++)
	{
		con[i][(i+1)%n] = con[(i+1)%n][i] = 1;
		con[i][(i+2)%n] = con[(i+2)%n][i] = 1;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(!con[i][j] && p)
			{
				con[i][j] = 1;
				p--;
			}
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(con[i][j])
				cout << i+1 << ' ' << j+1 << '\n';
}

int main()
{
	int t;
	cin >> t;
	int n,p;
	for(int i=0;i<t;i++)
	{
		cin >> n >> p;
		test(n,p);
	}
}