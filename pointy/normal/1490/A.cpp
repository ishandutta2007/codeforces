#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))

const int N=100001;
int n,m,T; 
int a[N];

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
	for (int i=1;i<=n;i++) a[i]=read();
	int ans=0;
	for (int i=1;i<n;i++)
	{
		int u=max(a[i],a[i+1]),v=min(a[i],a[i+1]);
		for (int j=1;j<=10;j++)
		{
			v*=2;
			if (v>=u) 
			{
				ans+=j-1;
				break;
			}
		}
	} 
	cout << ans << endl;
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}