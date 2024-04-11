#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 1511;
int f[MAXN][MAXN],fx[MAXN],diff=0;
struct one
{
	int p,l,r;
	bool operator< (const one& you)const{return p<you.p;}
}a[MAXN];
int place(int val){return std::lower_bound(fx+1,fx+diff+1,val)-fx;}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		int p=read(),x=read();
		int l=p-x,r=p+x;
		fx[++diff]=p,fx[++diff]=l,fx[++diff]=r;
		a[i]=one{p,l,r};
	}
	std::sort(a+1,a+n+1);
	std::sort(fx+1,fx+diff+1),diff=std::unique(fx+1,fx+diff+1)-fx-1;
	for(int i=1;i<=n;++i)a[i].p=place(a[i].p),a[i].l=place(a[i].l),a[i].r=place(a[i].r);
	for(int i=1;i<=n;++i)
	{
		int p=a[i].p,l=a[i].l,r=a[i].r;
		for(int j=p;j<=r;++j)umax(f[i][j],f[i-1][p]+fx[j]-fx[p]);
		int ed=p;
		for(int k=i;k;--k)
		{
			if(k<i)umax(ed,a[k].r);
			for(int j=l;j<=ed;++j)umax(f[i][j],f[k-1][l]+fx[j]-fx[l]);
		}
		for(int j=1;j<=diff;++j)umax(f[i][j],f[i-1][j]), umax(f[i][j],f[i][j-1]);
	}
	printf("%d\n",f[n][diff]);
	return 0;
}