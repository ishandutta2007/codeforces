#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=2e5+5;
const int p=1e9+7;
const int B=sqrt(M);

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
vector<int>fac[M];
int mn[M],id[N],cnt=0,pr[N];
void ysgs(int n)
{
	for (int i=2;i<=n;i++) if (!mn[i])
	for (int j=i;j<=n;j+=i) if (!mn[j]) mn[j]=i;
	for (int i=2;i<=B;i++) if (mn[i]==i) pr[id[i]=++cnt]=i;
	for (int i=2;i<=n;i++)
	for (int j=i;j>1;j/=mn[j])
	fac[i].push_back(mn[j]);
}
int len[105];
vector<int>b[105];
vector<vector<int>>mx[105];
int a[N],v[N],pre[N],Log[N];
const int LOG=20;
struct hjtree
{
	#define mid ((l+r)/2)
	struct node
	{
		int mul,ls,rs;
	}t[N*LOG];
	int root[N],cnt=0;
	void build(int &w,int l,int r)
	{
		t[w=++cnt].mul=1;
		if (l==r) return;
		build(t[w].ls,l,mid);
		build(t[w].rs,mid+1,r);
	}
	int insert(int w,int l,int r,int x,int y)
	{
		int now=++cnt;
		t[now]=t[w],t[now].mul=1LL*t[now].mul*y%p;
		if (l==r) return now;
		if (x<=mid) t[now].ls=insert(t[w].ls,l,mid,x,y);
			   else t[now].rs=insert(t[w].rs,mid+1,r,x,y);
		return now;
	}
	int query(int w,int l,int r,int ql,int qr)
	{
		if (qr<l||r<ql) return 1;
		if (ql<=l&&r<=qr) return t[w].mul;
		return 1LL*query(t[w].ls,l,mid,ql,qr)*query(t[w].rs,mid+1,r,ql,qr)%p;
	}
	#undef mid
}t;
int query(int w,int L,int R)
{
	if (b[w].empty()) return 0;
	int l=lower_bound(b[w].begin(),b[w].end(),L)-b[w].begin();
	int r=upper_bound(b[w].begin(),b[w].end(),R)-b[w].begin()-1;
	if (l>r) return 0;
	int k=Log[r-l+1];
	return max(mx[w][l][k],mx[w][r-(1<<k)+1][k]);
}

signed main()
{
	ysgs(2e5);
	int n=read();
	static int tot[105]={};
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		for (int j:fac[a[i]])
		if (j<=B) tot[id[j]]++;
			 else v[i]=j;
		for (int j:fac[a[i]]) if (j<=B&&tot[id[j]])
		{
			b[id[j]].push_back(i);
			mx[id[j]].push_back(vector<int>({tot[id[j]]}));
			tot[id[j]]=0;
		}
	}
	for (int i=2;i<=n;i++) Log[i]=Log[i/2]+1;
	for (int i=1;i<=cnt;i++)
	{
		int n=b[i].size();
		len[i]=Log[b[i].size()]+1;
		for (auto &j:mx[i]) j.resize(len[i]);
		for (int j=1;j<len[i];j++)
		for (int k=0;k+(1<<j)-1<n;k++)
		mx[i][k][j]=max(mx[i][k][j-1],mx[i][k+(1<<j-1)][j-1]);
	}
	static int lst[M];
	memset(lst,0,sizeof(lst));
	for (int i=1;i<=n;i++) if (v[i]) pre[i]=lst[v[i]],lst[v[i]]=i;
	t.build(t.root[0],0,n);
	for (int i=1;i<=n;i++)
	if (v[i]) t.root[i]=t.insert(t.root[i-1],0,n,pre[i],v[i]);
		 else t.root[i]=t.root[i-1];
	int Q=read();
	for (int T=1,lastans=0;T<=Q;T++)
	{
		int l=read(),r=read();
		l=(l+lastans)%n+1,r=(r+lastans)%n+1;
		if (l>r) swap(l,r);
		lastans=1LL*t.query(t.root[r],0,n,0,l-1)*power(t.query(t.root[l-1],0,n,0,l-1),p-2)%p;
		for (int i=1;i<=cnt;i++) lastans=1LL*lastans*power(pr[i],query(i,l,r))%p;
		print(lastans);
	}
	
	return 0;
}