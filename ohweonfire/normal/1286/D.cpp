// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=100111;
const int mod=998244353;
int qpow(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=(LL)ret*x%mod;
		x=(LL)x*x%mod;
		y>>=1;
	}
	return ret;
}

struct matrix
{
	int a[2][2];
	matrix(){memset(a,0,sizeof(a));}
	void set(int x){a[0][1]=a[1][0]=0;a[0][0]=a[1][1]=x;}
};
matrix operator *(const matrix&a,const matrix&b)
{
	matrix ret;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)ret.a[i][j]=(ret.a[i][j]+(LL)a.a[i][k]*b.a[k][j])%mod;
	return ret;
}
bool operator ==(const matrix&a,const matrix&b)
{
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)if(a.a[i][j]!=b.a[i][j])return false;
	return true;
}

matrix seg[300111];
#define ls (t<<1)
#define rs ((t<<1)|1)
void modify(int p,const matrix&v,int tl,int tr,int t)
{
	if(tl==tr)
	{
		seg[t]=v;
		return;
	}
	int mid=(tl+tr)>>1;
	if(p<=mid)modify(p,v,tl,mid,ls);
	else modify(p,v,mid+1,tr,rs);
	seg[t]=seg[ls]*seg[rs];
}

bool cmp(const pii&a,const pii&b){return (LL)a.ff*b.ss<(LL)a.ss*b.ff;}
bool cmp2(const pair<pii,int>&a,const pair<pii,int>&b){return cmp(a.ff,b.ff);}
bool eq(const pii&a,const pii&b){return (LL)a.ff*b.ss==(LL)a.ss*b.ff;}

int x[maxn],p[maxn],v[maxn],n;

void setv(int pos,pii t)
{
	matrix cur;
	cur.a[0][1]=1;
	if(cmp(t,mp(x[pos+1]-x[pos],abs(v[pos+1]-v[pos]))))cur.a[0][0]=cur.a[1][1]=1;
	else
	{
		cur.a[0][0]=(v[pos+1]<=v[pos]);
		cur.a[1][1]=(v[pos+1]>=v[pos]);
	}
	if(cmp(t,mp(x[pos+1]-x[pos],v[pos+1]+v[pos])))cur.a[1][0]=1;
	
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)
	{
		if(j==0)cur.a[i][j]=(LL)cur.a[i][j]*(mod+1-p[pos+1])%mod;
		else cur.a[i][j]=(LL)cur.a[i][j]*p[pos+1]%mod;
	}
//	printf("Setv %d\n",pos);
//	for(int i=0;i<2;i++)for(int j=0;j<2;j++)printf("i= %d j= %d p= %d\n",i,j,cur.a[i][j]);
	modify(pos,cur,1,n-1,1);
}

int calc()
{
	int prob=0;
	matrix cur=seg[1];
	for(int j=0;j<2;j++)for(int k=0;k<2;k++)
	{
		int coef=cur.a[j][k];
		if(j==0)coef=(LL)coef*(mod+1-p[1])%mod;
		else coef=(LL)coef*p[1]%mod;
		prob+=coef;
		if(prob>=mod)prob-=mod;
	}
	return prob;
}

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get3(x[i],v[i],p[i]);
		p[i]=(LL)p[i]*qpow(100,mod-2)%mod;
	}
	
	vector<pair<pii,int> >vs;
	for(int pos=1;pos<n;pos++)
	{
		if(v[pos]!=v[pos+1])vs.pb(mp(mp(x[pos+1]-x[pos],abs(v[pos+1]-v[pos])),pos));
		vs.pb(mp(mp(x[pos+1]-x[pos],v[pos+1]+v[pos]),pos));
		vs.pb(mp(mp(2000000001,1),pos));
	}
	sort(vs.begin(),vs.end(),cmp2);
	
	pii cur=mp(0,1);
	for(int i=1;i<n;i++)setv(i,cur);
	int ans=0,last=calc();
	for(int i=0,nxt=0;i<(int)vs.size();i=nxt)
	{
		for(;nxt<(int)vs.size()&&eq(vs[i].ff,vs[nxt].ff);nxt++);
		for(int j=i;j<nxt;j++)setv(vs[j].ss,vs[j].ff);
//		for(int j=1;j<n;j++)setv(j,vs[i].ff);
		
		int prob=calc();
		ans=(ans+(LL)(last-prob+mod)*vs[i].ff.ff%mod*qpow(vs[i].ff.ss,mod-2))%mod;
//		printf("t= %d %d prob= %d\n",vs[i].ff.ff,vs[i].ff.ss,prob);
		
		cur=vs[i].ff;
		last=prob;
	}
	printendl(ans);
	return 0;
}