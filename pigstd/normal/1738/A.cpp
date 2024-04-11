#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=1e5+10;
int n,a[M],b[M];
vector<int>v[2];

void solve()
{
	v[0].clear(),v[1].clear();
	n=read();int s=0;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)b[i]=read(),v[a[i]].pb(b[i]),s+=b[i];
	if (v[0].size()<v[1].size())swap(v[0],v[1]);
	sort(v[0].begin(),v[0].end());
	reverse(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());
	reverse(v[1].begin(),v[1].end());
	for (int i=0;i<(int)(v[1].size());i++)s+=v[0][i]+v[1][i];
	if (v[0].size()==v[1].size())s-=min(v[0][v[0].size()-1],v[1][v[0].size()-1]);
	cout<<s<<'\n';
}

signed main()
{
	WT solve();
	return 0;
}