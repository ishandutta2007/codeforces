#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))

const int N=101;
int n,m,T; 
int a[N];
bool used[N][N];

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 

void work()
{
	n=read();
	if (n%2==1)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if ((i+j)%2==0) cout << 1 << " ";
				else cout << -1 << " ";
			}
		}
		return;
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (i%2==1&&i==j-1) cout << 0 << " ";
				else if ((i+j)%2==0) cout << 1 << " ";
				else cout << -1 << " ";
			}
		}
		return;
	}
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
		cout << endl;
	}
	return 0;
}