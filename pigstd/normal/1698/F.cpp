#include<bits/stdc++.h>
//#define int long long
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

const int M=510;
int n,a[M],b[M];
pii p1[M],p2[M];

void solve()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)b[i]=read();
	if (a[1]!=b[1])return puts("NO"),void();
	for (int i=1;i<n;i++)p1[i]=mp(min(a[i],a[i+1]),max(a[i],a[i+1]));
	for (int i=1;i<n;i++)p2[i]=mp(min(b[i],b[i+1]),max(b[i],b[i+1]));
	sort(p1+1,p1+n),sort(p2+1,p2+n);
	for (int i=1;i<n;i++)if (p1[i]!=p2[i])return puts("NO"),void();
	puts("YES");
	vector<pii>ans;
	for (int i=1;i<n;i++)
	{
		if (a[i+1]==b[i+1])continue;
		int f=0;
		for (int j=i+1;j<n;j++)
			if (a[j]==b[i+1]&&a[j+1]==a[i])
			{
				f=1,ans.pb(mp(i,j+1));
				reverse(a+i,a+j+2);
				break;
			}
		if (f)continue;
		int pos=-1;
		for (int j=i+1;j<n;j++)
			if (a[j]==a[i]&&a[j+1]==b[i+1]){pos=j;break;}
		assert(pos!=-1);
		for (int j=i;j<=pos&&!f;j++)for (int k=pos+1;k<=n&&!f;k++)
			if (a[j]==a[k])ans.pb(mp(j,k)),f=1,reverse(a+j,a+k+1);
		for (int j=i+1;j<n;j++)
			if (a[j]==b[i+1]&&a[j+1]==a[i])
			{
				ans.pb(mp(i,j+1));
				reverse(a+i,a+j+2);
				break;
			}
	}
	cout<<ans.size()<<'\n';
	for (auto x:ans)cout<<x.x<<' '<<x.y<<'\n';
}

signed main()
{
	WT solve();
	return 0;
}