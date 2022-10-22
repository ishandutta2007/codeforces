//AFO countdown:9 Days
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

const int Mod=1e9+7;
const int B=87;
const int M=1e5+10;
int n,q,f[M<<1],prime[M],cnt,a[M],lg2[M],la;
int rt[M],val[M<<6],tl[M<<6],tr[M<<6],t[M<<1],tot;

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

int inv(int x){return poww(x,Mod-2);}

int build(int l,int r)
{
	int k=++tot;val[k]=1;
	if (l!=r)
	{
		int Mid=(l+r)>>1;
		tl[k]=build(l,Mid),
		tr[k]=build(Mid+1,r);
	}return k;
}

int update(int pre,int l,int r,int x1,int x2,int p)
{
	int Mid=(l+r)>>1,k=++tot;
	if (l==r)
	{
		if (l==x1)val[k]=p*val[pre]%Mod;
		else val[k]=inv(p)*val[pre]%Mod;
		return k;
	}
	if ((x1>=l&&x1<=Mid)||(x2>=l&&x2<=Mid))
		tl[k]=update(tl[pre],l,Mid,x1,x2,p);
	else tl[k]=tl[pre];
	if ((x1>Mid&&x1<=r)||(x2>Mid&&x2<=r))
		tr[k]=update(tr[pre],Mid+1,r,x1,x2,p);
	else tr[k]=tr[pre];
	val[k]=val[tl[k]]*val[tr[k]]%Mod;
	return k;
}

int query(int now,int l,int r,int p)
{
	if (now==0)while(1);
	int Mid=(l+r)>>1;
	if (p<l)return 1;
	if (r<=p)return val[now];
	return query(tl[now],l,Mid,p)*query(tr[now],Mid+1,r,p)%Mod;
}

struct ST
{
	char f[M][20];
	void init()
	{
		for (int j=1;j<=18;j++)
			for (int i=1;i+(1<<j)-1<=n;i++)
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
	int query(int l,int r)
	{
		int k=lg2[r-l+1];
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
}T[90];

signed main()
{
	for (int i=2;i<=2e5;i++)
	{
		if (f[i])continue;
		prime[++cnt]=i;
		for (int j=i*i;j<=2e5;j+=i)
			f[j]=1;
	}
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		for (int j=1;j<=B;j++)
		{
			int res=0;
			while(a[i]%prime[j]==0)
				a[i]/=prime[j],res++;
			T[j].f[i][0]=res;
		}
//		cout<<a[i]<<' ';
	}//puts(""); 
	q=read();
	for (int i=1;i<=B;i++)
		T[i].init();
	for (int i=2;i<=n;i++)
		lg2[i]=lg2[i>>1]+1;
//	puts("qwq");
	rt[0]=build(1,n);
	for (int i=1;i<=n;i++)
		rt[i]=update(rt[i-1],1,n,t[a[i]]+1,i+1,a[i]),
		t[a[i]]=i;
	while(q--)
	{
		int l=(read()+la)%n+1,r=(read()+la)%n+1;
		if (l>r)swap(l,r);int res=1;
		for (int i=1;i<=87;i++)
			res=res*poww(prime[i],T[i].query(l,r))%Mod;
//		puts("qwqwq");
		res=res*query(rt[r],1,n,l)%Mod;
		cout<<(la=res)<<endl;
	}
	return 0;
}
// /tuu