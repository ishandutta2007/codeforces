// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

namespace matching{

const int MaxN = 1205;
const int MaxM = MaxN * (MaxN - 1);

int n, m;
int nE, adj[MaxN];
int next[MaxM], go[MaxM];

inline void addEdge(const int &u, const int &v)
{
//	cout<<"edge "<<u<<' '<<v<<endl;
	next[++nE] = adj[u], go[adj[u] = nE] = v;
	next[++nE] = adj[v], go[adj[v] = nE] = u;
}

int n_matches;
int mate[MaxN];

int q_n;
int q[MaxN];
int book_mark;
int book[MaxN];

int type[MaxN];
int fa[MaxN];
int bel[MaxN];

inline void augment(int u)
{
	while (u)
	{
		int nu = mate[fa[u]];
		mate[mate[u] = fa[u]] = u;
		u = nu;
	}
}

inline int get_lca(int u, int v)
{
	++book_mark;
	while (true)
	{
		if (u)
		{
			if (book[u] == book_mark)
				return u;
			book[u] = book_mark;
			u = bel[fa[mate[u]]];
		}
		swap(u, v);
	}
}

inline void go_up(int u, int v, const int &mv)
{
	while (bel[u] != mv)
	{
		fa[u] = v;
		v = mate[u];
		if (type[v] == 1)
			type[q[++q_n] = v] = 0;
		if (bel[u] == u)
			bel[u] = mv;
		if (bel[v] == v)
			bel[v] = mv;
		u = fa[v];
	}
}
inline void after_go_up()
{
	for (int u = 1; u <= n; ++u)
		bel[u] = bel[bel[u]];
}

inline bool match(const int &sv)
{
	for (int u = 1; u <= n; ++u)
		bel[u] = u, type[u] = -1;
	type[q[q_n = 1] = sv] = 0;

	for (int i = 1; i <= q_n; ++i)
	{
		int u = q[i];
		for (int e = adj[u]; e; e = next[e])
		{
			int v = go[e];
			if (!~type[v])
			{
				fa[v] = u, type[v] = 1;
				int nu = mate[v];
				if (!nu)
				{
					augment(v);
					return true;
				}
				type[q[++q_n] = nu] = 0;
			}
			else if (!type[v] && bel[u] != bel[v])
			{
				int lca = get_lca(u, v);
				go_up(u, v, lca);
				go_up(v, u, lca);
				after_go_up();
			}
		}
	}
	return false;
}

inline void calc_max_match()
{
	n_matches = 0;
	for (int u = 1; u <= n; ++u)
		if (!mate[u] && match(u))
			++n_matches;
}

}

int n;
int a[300005],f[605],hv[605],res[300005];
bool vis[300005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

bool merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy){
		if(hv[fx]) return false;
		hv[fx]=1;
		return true;
	}
	if(hv[fx]&&hv[fy]) return false;
	f[fx]=fy;
	hv[fy]|=hv[fx];
	return true;
}

int main(){
//	mt19937 mrand(123);
	n=readint();
//	n=300000;
	for(int i=1;i<=n;i++) a[i]=readint();
//	for(int i=1;i<=n;i++) a[i]=mrand()&1?0:(mrand()%600+1);
	for(int i=1;i<n;i++) if(a[i]==a[i+1]&&a[i]) vis[a[i]]=1;
	vis[0]=1;
	int ans=0;
	for(int i=1;i<=600;i++) ans+=vis[i];
	int cnt=600;
	for(int i=1;i<=600;i++) f[i]=i,hv[i]=0;
	hv[0]=1;
	for(int i=1;i<=n;i++){
		if(a[i]==0&&(i==1||a[i-1]!=0)){
			int j=i;
			while(j<=n&&!a[j]) j++;
			j--;
			if((j-i+1)%2==0){
				if(vis[a[i-1]]||vis[a[j+1]]) ans+=(j-i+1)/2;
				else matching::addEdge(a[i-1],a[j+1]),ans+=(j-i+1)/2;
			}
			else{
				ans+=(j-i+1)/2;
				if(merge(a[i-1],a[j+1])){
					cnt++;
					if(!vis[a[i-1]]) matching::addEdge(a[i-1],cnt);
					if(!vis[a[j+1]]) matching::addEdge(cnt,a[j+1]);
				}
			}
//			cout<<"test "<<i<<' '<<j<<endl;
			i=j;
		}
	}
	matching::n=cnt;
	matching::calc_max_match();
	cnt=600;
	for(int i=1;i<=n;i++) res[i]=a[i];
	for(int i=1;i<=600;i++) f[i]=i,hv[i]=0;
	hv[0]=1;
	for(int i=1;i<=n;i++){
		if(a[i]==0&&(i==1||a[i-1]!=0)){
			int j=i;
			while(j<=n&&!a[j]) j++;
			j--;
			if((j-i+1)%2==0){
				if(vis[a[i-1]]||vis[a[j+1]]) ans+=(j-i+1)/2;
				else{
					if(matching::mate[a[i-1]]==a[j+1]){
						res[i]=a[i-1],res[j]=a[j+1];
						matching::mate[a[i-1]]=matching::mate[a[j+1]]=0;
					}
					ans+=(j-i+1)/2;
				}
			}
			else{
				ans+=(j-i+1)/2;
				if(merge(a[i-1],a[j+1])){
					cnt++;
					if(matching::mate[cnt]==a[i-1]) res[i]=a[i-1];
					else if(matching::mate[cnt]==a[j+1]) res[j]=a[j+1];
				}
			}
			i=j;
		}
	}
	for(int i=1;i<n;i++) if(res[i]==res[i+1]&&res[i]) vis[res[i]]=1;
	int now=1;
	while(vis[now]) now++;
	for(int i=1;i<n;i++){
		if(!res[i]&&!res[i+1]){
			res[i]=res[i+1]=now;
			vis[now]=1;
			while(vis[now]) now++;
		}
	}
	for(int i=1;i<=n;i++) if(!res[i]) res[i]=1;
	for(int i=1;i<=n;i++) printf("%d ",res[i]);
	printf("\n");
	return 0;
}