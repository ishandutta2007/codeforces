#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=200005,INF=0x3f3f3f3f;

int n,src,sink,a[MAXN];
int que[MAXN],front,rear,dis[MAXN];
int Max[2][MAXN<<2];
vector<int> al;
void build(int ty,int id,int l,int r)
{
	if(l==r){Max[ty][id]=(ty==0?a[l]+l:a[l]-l);return;}
	int mid=(l+r)>>1;
	build(ty,id<<1,l,mid);
	build(ty,id<<1|1,mid+1,r);
	Max[ty][id]=max(Max[ty][id<<1],Max[ty][id<<1|1]);
}
void modify(int ty,int id,int l,int r,int x,int c)
{
	if(l==r){Max[ty][id]=c;return;}
	int mid=(l+r)>>1;
	if(x<=mid)modify(ty,id<<1,l,mid,x,c);
	else modify(ty,id<<1|1,mid+1,r,x,c);
	Max[ty][id]=max(Max[ty][id<<1],Max[ty][id<<1|1]);
}
void select(int ty,int id,int l,int r,int ql,int qr,int c)
{
	if(Max[ty][id]<c)return;
	if(l==r){al.pb(l);return;}
	int mid=(l+r)>>1;
	if(ql<=mid)select(ty,id<<1,l,mid,ql,min(qr,mid),c);
	if(qr>mid)select(ty,id<<1|1,mid+1,r,max(ql,mid+1),qr,c);
}
void calc(int u,int d)
{
	dis[u]=d;
	modify(0,1,1,n,u,-INF),modify(1,1,1,n,u,-INF);
	que[++rear]=u;
}
void work(int ty,int l,int r,int u)//0:i+a[i]>=u 1:i-a[i]<=u (a[i]-i>=-u)
{
	if(r<=0 || l>n)return;
	chkmax(l,1),chkmin(r,n);
	al.clear();
	select(ty,1,1,n,l,r,ty==0?u:-u);
	for(auto i:al)calc(i,dis[u]+1);
}
void solve()
{
	readint(n),readint(src),readint(sink);
	for(int i=1;i<=n;++i)readint(a[i]),dis[i]=INF;
	build(0,1,1,n),build(1,1,1,n);
	front=1,rear=0,que[++rear]=src;
	calc(src,0);
	while(front<=rear)
	{
		int u=que[front++];
		work(0,u-a[u],u-1,u),work(1,u+1,u+a[u],u);
	}
	printf("%d\n",dis[sink]);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}