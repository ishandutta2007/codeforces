#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 211,P = 205;
const ll LINF=1e18+233;
struct matrix
{
	ll a[MAXN][MAXN];
	matrix(){memset(a,0xcf,sizeof a);}
	matrix(ll b[MAXN][MAXN]){memcpy(a,b,sizeof a);}
	matrix operator* (matrix you)
	{
		static ll tp[MAXN][MAXN];
		memset(tp,0xcf,sizeof tp);
		for(int i=0;i<MAXN;++i)
			for(int k=0;k<MAXN;++k)
				for(int j=0;j<MAXN;++j)umax(tp[i][j],a[i][k]+you.a[k][j]);
		return matrix(tp);
	}
}A;
matrix Qpow(matrix A,ll p)
{
	matrix res;
	for(int i=0;i<MAXN;++i)res.a[i][i]=0;
	while(p)
	{
		if(p&1)res=res*A;
		A=A*A,p>>=1;
	}
	return res;
}
namespace AC
{
	int t[MAXN][26],val[MAXN], tot;
	void insert(char* a,int k)
	{
		//printf("insert,k=%d\n",k);
		int n=strlen(a+1),u=0;
		for(int i=1;i<=n;++i)
		{
			int &v=t[u][a[i]-'a'];
			if(!v)v=++tot;
			u=v;
			//printf("u=%d\n",u);
		}
		val[u]+=k;
	}
	int Q[MAXN],fail[MAXN];
	void build()
	{
		int Qh=0,Qt=0;
		for(int c=0;c<26;++c)
			if(t[0][c])Q[Qt++]=t[0][c];
		while(Qh<Qt)
		{
			int u=Q[Qh++];
			val[u]+=val[fail[u]];
			for(int c=0;c<26;++c)
			{
				int &v=t[u][c];
				if(!v)v=t[fail[u]][c];
				else fail[v]=t[fail[u]][c],Q[Qt++]=v;
			}
		}
		for(int u=0;u<=tot;++u)
		{
			//printf("Fail[%d]=%d\n",u,fail[u]);
			for(int c=0;c<26;++c)
			{
				A.a[u][t[u][c]]=val[t[u][c]];
				//if(t[u][c])printf("T[%d,%d]=%d\n",u,c,t[u][c]);
			}
		}
	}
}
int val[MAXN];
char a[MAXN];
int main()
{
	int n=read();
	ll l=read();
	for(int i=1;i<=n;++i)val[i]=read();
	for(int i=1;i<=n;++i)scanf("%s",a+1),AC::insert(a,val[i]);
	AC::build();
	matrix res=Qpow(A,l);
	ll ans=-LINF;
	for(int i=0;i<MAXN;++i)umax(ans,res.a[0][i]);
	printf("%lld\n",ans);
	return 0;
}