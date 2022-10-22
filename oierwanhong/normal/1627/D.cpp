#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 1000011,V = 1000000;
/*std::vector<pii>d[MAXN];
bool vis[MAXN];
void sieve(int n)
{
	for(int i=1;i<=n;++i)rest[i]=i;
	vis[1]=1;
	for(int i=2;i<=n;++i)
		if(!vis[i])
		{
			for(int j=i;j<=n;j+=i)
			{
				int c=0;
				while(rest[j]%i==0)rest[j]/=i,++c;
				d[j].emplace_back(pii(i,c));
			}
		}
}
*/
int gcd(int a,int b){return b?gcd(b,a%b):a;}
bool vis[MAXN];
int main()
{
	//sieve(V);
	int n=read(),ans=0;
	for(int i=1;i<=n;++i)vis[read()]=1;
	for(int i=1;i<=V;++i)
		if(!vis[i])
		{
			int g=0;
			for(int j=i;j<=V;j+=i)
				if(vis[j])g=gcd(g,j);
			if(g==i)++ans;
		}
	printf("%d\n",ans);
	return 0;
}