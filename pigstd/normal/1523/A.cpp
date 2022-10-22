#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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

const int inf=1e18;
const int M=1e3+10;
int n,m;
int a[M],a1[M],a2[M];
string s;

signed main()
{
	WT
	{
		n=read(),m=read();cin>>s;
		for (int i=1;i<=n;i++)
			a[i]=s[i-1]-'0';
		a1[0]=-inf;
		for (int i=1;i<=n;i++)
			if (a[i])a1[i]=i;
			else a1[i]=a1[i-1];
		a2[n+1]=inf;
		for (int i=n;i>=1;i--)
			if (a[i])a2[i]=i;
			else a2[i]=a2[i+1];
		for (int i=1;i<=n;i++)
		{
			if (a[i])cout<<1;
			else
			{
				if (i-a1[i]==a2[i]-i)cout<<0;
				else if (i-a1[i]<=m||a2[i]-i<=m)cout<<1;
				else cout<<0;
			}
		}puts("");
	}
	return 0;
}