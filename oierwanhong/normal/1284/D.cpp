#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<random>
#include<chrono>
typedef unsigned un;
typedef unsigned long long ull;
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 800011;
int fx[MAXN],diff=0;
int place(int val){return std::lower_bound(fx+1,fx+diff+1,val)-fx;}
ull val[MAXN];
struct one
{
	int x,dex;
}p[MAXN];
bool cmp1(one a,one b){return a.x<b.x||(a.x==b.x&&a.dex>b.dex);}
bool cmp2(one a,one b){return a.x>b.x||(a.x==b.x&&a.dex>b.dex);}
void solve(ull* res,pii* a,int n)
{
	int cnt=0;
	for(int i=1;i<=n;++i)p[++cnt]=one{a[i].first,i},p[++cnt]=one{a[i].second,-i};
	std::sort(p+1,p+cnt+1,cmp1);
	ull cur=0;
	for(int i=1;i<=cnt;++i)
		if(p[i].dex<0)cur^=val[-p[i].dex];
		else res[p[i].dex]^=cur;
	cnt=0;
	for(int i=1;i<=n;++i)p[++cnt]=one{a[i].second,i},p[++cnt]=one{a[i].first,-i};
	std::sort(p+1,p+cnt+1,cmp2);
	cur=0;
	for(int i=1;i<=cnt;++i)
		if(p[i].dex<0)cur^=val[-p[i].dex];
		else res[p[i].dex]^=cur;
}
pii a[MAXN],b[MAXN];
ull res1[MAXN],res2[MAXN];
int main()
{
	std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());
	int n=read(),cnt=0;
	for(int i=1;i<=n;++i)a[i].first=read(),a[i].second=read(),b[i].first=read(),b[i].second=read();
	for(int i=1;i<=n;++i)val[i]=rd();
	solve(res1,a,n),solve(res2,b,n);
	for(int i=1;i<=n;++i)
	{
		//fprintf(stderr,"%llu %llu\n",res1[i],res2[i]);
		if(res1[i]!=res2[i]){puts("NO");return 0;}
	}
	puts("YES");
	return 0;
}