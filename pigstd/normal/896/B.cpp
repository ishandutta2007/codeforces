#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e3+10;
int n,m,c,a[M];

signed main()
{
	cin>>n>>m>>c;int cnt=0;
	for (int i=1;i<=m;i++)
	{
		int x;cin>>x;
		if (x<=(c+1)/2)
		{
			for (int j=1;j<=n;j++)
				if (a[j]==0||a[j]>x)
				{
					cnt+=a[j]==0;
					cout<<j<<endl;
					a[j]=x;break;
				}
		}
		else
		{
			for (int j=n;j>=1;j--)
				if (a[j]==0||a[j]<x)
				{
					cnt+=a[j]==0;
					cout<<j<<endl;
					a[j]=x;break;
				}
				
		}
		if (cnt==n)break;
	}
	return 0;
}