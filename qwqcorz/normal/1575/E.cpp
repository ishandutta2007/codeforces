#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

inline void add(int &x,int y){x+=y;if (x>=p) x-=p;}
struct edge{int to,val;};
vector<edge>e[N];
int n,k,a[N],sum[N],len[N],son[N],ans=0;
int cntdp=0,cnta=0,null=0;
struct myArray
{
	vector<int>a,s;
	inline int size(){return a.size();}
	inline void extend(int x)
	{
		a.push_back(x);
		s.push_back(((s.empty()?0:s.back())+x)%p);
	}
	inline int get(int x){return size()-x;}
	inline int &val(int x){return x<=size()?a[get(x)]:null;}
	inline int calc(int l,int r)
	{
		r=min(r,size());
		if (l>r) return 0;
		int L=get(r),R=get(l);
		return (s[R]-(L?s[L-1]:0)+p)%p;
	}
	inline void clear(){a.clear(),s.clear();}
	inline void merge(myArray &x)
	{
		if (size()<x.size())
		{
			int tmp=x.size()-size();
			a.insert(a.begin(),tmp,0);
			s.insert(s.begin(),tmp,0);
		}
		int m=x.size();
		for (int i=1;i<=m;i++) val(i)=(val(i)+x.val(i))%p;
		for (int i=m;i>=1;i--) s[get(i)]=((get(i)?s[get(i)-1]:0)+val(i))%p;
	}
}tmpa[N*4];
struct DP
{
	myArray *f[2],*g[2];
	inline int size(){return max(f[0]->size(),f[1]->size());}
}tmpdp[N],*dp[N];
void add_edge(int now,DP &d,int x)
{
	d.f[!x]->extend(1);
	d.g[!x]->extend(sum[now]);
	if (d.f[x]->size()>d.f[!x]->size())
	{
		d.f[x]->merge(*d.f[!x]);
		d.g[x]->merge(*d.g[!x]);
	}
	else
	{
		d.f[!x]->merge(*d.f[x]);
		d.g[!x]->merge(*d.g[x]);
		swap(d.f[x],d.f[!x]);
		swap(d.g[x],d.g[!x]);
	}
	d.f[!x]->clear();
	d.g[!x]->clear();
}
void merge(DP &now,DP &to,int S)
{
	for (int x=0;x<=1;x++)
	for (int y=0;y<=1;y++)
	{
		int m=to.f[y]->size();
		if (!m) continue;
		for (int i=1;i<=min(m,k-(x!=y));i++)
		add(ans,(1LL*to.f[y]->val(i)*now.g[x]->calc(1,k-i+(x==y))
				+1LL*to.g[y]->val(i)*now.f[x]->calc(1,k-i+(x==y))
				-1LL*to.f[y]->val(i)*now.f[x]->calc(1,k-i+(x==y))%p*S%p+p)%p);
	}
	for (int x=0;x<=1;x++)
		now.f[x]->merge(*to.f[x]),
		now.g[x]->merge(*to.g[x]);
}
void dfs(int now,int father)
{
	sum[now]=(sum[father]+a[now])%p;
	for (edge i:e[now])
	{
		int to=i.to;
		if (to==father) continue;
		dfs(to,now);
		add_edge(to,*dp[to],i.val);
		add(ans,((dp[to]->g[0]->calc(1,k)+dp[to]->g[1]->calc(1,k)
			-1LL*(dp[to]->f[0]->calc(1,k)+dp[to]->f[1]->calc(1,k))*sum[father])%p+p)%p);
		if (len[now]<dp[to]->size())
		{
			len[now]=dp[to]->size();
			son[now]=to;
		}
	}
	if (son[now]) dp[now]=dp[son[now]];
	else
	{
		dp[now]=&tmpdp[++cntdp];
		tmpdp[cntdp].f[0]=&tmpa[++cnta];
		tmpdp[cntdp].f[1]=&tmpa[++cnta];
		tmpdp[cntdp].g[0]=&tmpa[++cnta];
		tmpdp[cntdp].g[1]=&tmpa[++cnta];
	}
	for (edge i:e[now])
	{
		int to=i.to;
		if (to==father||to==son[now]) continue;
		merge(*dp[now],*dp[to],sum[now]+sum[father]);
	}
}

signed main()
{
	n=read(),k=read()+1;
	for (int i=1;i<=n;i++) add(ans,a[i]=read());
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
	}
	dfs(1,0);
	print(ans);
	
	return 0;
}