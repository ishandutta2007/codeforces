#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
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

const int M=1e6+10;
int n,m,t[M];
vector<int>a[M];
string s;

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m+1;i++)t[i]=1e18;
	for (int i=1;i<=n;i++)
	{
		a[i].pb(0);cin>>s;
		for (int j=1;j<=m;j++)
			a[i].pb(s[j-1]=='X'?1:0);
	}
	for (int i=2;i<=n;i++)
		for (int j=2;j<=m;j++)
			if (a[i-1][j]&&a[i][j-1])t[j]=j;
	for (int i=m;i>=1;i--)
		t[i]=min(t[i],t[i+1]);
	WT
	{
		int l=read(),r=read();
		if (t[l+1]>r)YES
		else NO
	}
	return 0;
}