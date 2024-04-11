#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=75;
const int S=1<<8;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct matrix
{
	int n,m,a[N][N];
	matrix(int _n=0,int _m=0)
	{
		n=_n,m=_m;
		memset(a,0,sizeof(a));
	}
	friend matrix operator *(const matrix &a,const matrix &b)
	{
		matrix ret(a.n,b.m);
		memset(ret.a,0x3f,sizeof(ret.a));
		for (int i=1;i<=a.n;i++)
		for (int k=1;k<=a.m;k++)
		for (int j=1;j<=b.m;j++)
//		print(i,','),print(j,','),print(k,':'),print(a.a[i][k]+b.a[k][j]),
		ret.a[i][j]=min(ret.a[i][j],a.a[i][k]+b.a[k][j]);
		return ret;
	}
}tr[30],ans;
struct node
{
	int pos,val;
	bool operator <(const node &a)const
	{
		return pos<a.pos;
	}
}a[N];
int c[N],b[30*8];
int st[N],id[S],cnt=0;
void power(matrix &a,int b)
{
	for (int i=0;i<30&&b;i++,b/=2) if (b&1) a=a*tr[i];
}
void GreenDay()
{
	int n=read(),k=read(),m=read(),q=read();
	for (int i=1;i<=k;i++) c[i]=read();
	for (int i=1;i<=q;i++) a[i].pos=read(),a[i].val=read();
	sort(a+1,a+1+q);
	for (int i=1;i<(1<<k);i++)
	if (__builtin_popcount(i)==n)
	st[id[i]=++cnt]=i;
	tr[0]=matrix(cnt,cnt);
	memset(tr[0].a,0x3f,sizeof(tr[0].a));
	for (int i=1;i<=cnt;i++)
	if (st[i]&1)
	{
		int nxt=st[i]>>1;
		for (int j=1;j<=k;j++) if (~st[i]>>j&1) tr[0].a[i][id[nxt|1<<j-1]]=c[j];
	}
	else tr[0].a[i][id[st[i]>>1]]=0;
	for (int i=1;i<30;i++) tr[i]=tr[i-1]*tr[i-1];
	ans=matrix(1,cnt);
	for (int i=2;i<=cnt;i++) ans.a[1][i]=1LL<<60;
	int cntb=0;
	b[0]=a[0].pos=k;
	b[++cntb]=a[q+1].pos=m-n+k;
	for (int i=1;i<=q;i++)
	for (int j=0;j<8&&a[i].pos+j<=m-n+k;j++)
	if (a[i].pos+j>k) b[++cntb]=a[i].pos+j;
	sort(b,b+1+cntb);
	cntb=unique(b,b+1+cntb)-b-1;
	for (int i=1;i<=cntb;i++)
	{
		power(ans,b[i]-b[i-1]-1);
		int ex[10]={};
		for (int j=1;j<=q;j++)
		if (b[i]-k<a[j].pos&&a[j].pos<=b[i])
		ex[a[j].pos-(b[i]-k)]=a[j].val;
		matrix tmp=matrix(cnt,cnt);
		memset(tmp.a,0x3f,sizeof(tmp.a));
		for (int i=1;i<=cnt;i++)
		if (st[i]&1)
		{
			int nxt=st[i]>>1;
			for (int j=1;j<=k;j++) if (~st[i]>>j&1) tmp.a[i][id[nxt|1<<j-1]]=c[j]+ex[j];
		}
		else tmp.a[i][id[st[i]>>1]]=0;
		ans=ans*tmp;
	}
	print(ans.a[1][1]);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}
/*
2 8 10 2
1 2 3 1000 1000 1000 1000 1000
5 -10
6 1000
*/