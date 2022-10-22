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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
int n,k,cnt,ans[M],l[M],ed[M],de[M];
vector<int>e[M];

bool cmp(int a,int b){return a>b;}

void dfs1(int u,int fa)
{
	int sum=0;
	for (auto to:e[u])
		if (to!=fa)sum++,dfs1(to,u);
	if (!sum)cnt++;
}

void dfs2(int u,int fa)
{
	int sum=0;de[u]=1;
	for (auto to:e[u])
		if (to!=fa)
		{
			sum++,dfs2(to,u);
			if (de[to]+1>de[u]||ed[u]==0)ed[u]=ed[to],de[u]=de[to]+1;
		}
	if (!sum)ed[u]=u;l[ed[u]]++;
}

signed main()
{
//	freopen("qwq.txt","r",stdin);
//	freopen("1.out","w",stdout);
	n=read(),k=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}dfs1(1,0);
	if (cnt<=k)
	{
		if (k<=n/2)cout<<k*(n-k);
		else
		{
			int p=max(cnt,n/2);
			cout<<p*(n-p);
		}
		return 0;
	}ans[0]=n;dfs2(1,0);int res=-1e18;
	sort(l+1,l+1+n,cmp);
//	for (int i=1;i<=n;i++)cout<<ed[i]<<' ';puts("");
	for (int i=1;i<=k;i++)ans[i]=ans[i-1]-l[i];
	for (int i=0;i<=k;i++)
	{
//		cout<<i<<' '<<ans[i]<<endl;
		int x=n-i;
		if (ans[i]>(x+i)/2)ckmax(res,(x-(x+i)/2)*(i-(x+i)/2));
		else ckmax(res,(i-ans[i])*(x-ans[i]));
	}cout<<res<<endl;
	return 0;
}