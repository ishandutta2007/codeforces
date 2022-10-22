#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
int n,ans[M],a[M];
vector<int>v[M],v2[M];

void solve()
{
	n=read();
	for (int i=1;i<=n;i++)v[i].clear(),v2[i].clear();
	for (int i=1;i<=n;i++)v[a[i]=read()].pb(i);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=v[i].size();j++)
			v2[j].pb(i);
	for (int i=n;i>=1;i--)
	{
		if (!v2[i].size())continue;
		vector<int>v3;
		for (auto x:v2[i])
		{
			int sz=v[x].size();
			v3.pb(v[x][sz-1]),v[x].pop_back();
		}
		for (int i=0;i<v3.size();i++)
			if (i+1==v3.size())ans[v3[0]]=v3[i];
			else ans[v3[i+1]]=v3[i];
	}
	for (int i=1;i<=n;i++)cout<<a[ans[i]]<<' ';puts("");
}

signed main()
{
	WT solve();
	return 0;
}