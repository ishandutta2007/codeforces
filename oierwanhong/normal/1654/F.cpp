#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 19;
char a[1000011];
std::vector<int>pos[26];
int rank[1<<MAXN];
struct one
{
	int a,b,dex;
	bool operator< (const one& you)const
	{
		if(a==you.a)return b<you.b;
		return a<you.a;
	}
	bool operator== (const one& you)const{return a==you.a&&b==you.b;}
	bool operator!= (const one& you)const{return !((*this)==you);}
}b[1<<MAXN];
int main()
{
	int n=read();
	scanf("%s",a);
	for(int i=0;i<(1<<n);++i)b[i]=one{a[i]-'a',0,i};
	std::sort(b,b+(1<<n));
	int cur=0;
	for(int i=0;i<(1<<n);++i)
		if(i&&b[i]!=b[i-1])rank[b[i].dex]=++cur;
		else rank[b[i].dex]=cur;
	for(int x=1;x<=n;++x)
	{
		for(int i=0;i<(1<<n);++i)b[i]=one{rank[i],rank[i^(1<<(x-1))],i};
		std::sort(b,b+(1<<n));
		int cur=0;
		for(int i=0;i<(1<<n);++i)
			if(i&&b[i]!=b[i-1])rank[b[i].dex]=++cur;
			else rank[b[i].dex]=cur;
	}
	for(int i=0;i<(1<<n);++i)
		if(rank[i]==0)
		{
			for(int j=0;j<(1<<n);++j)putchar(a[i^j]);
			puts("");
			return 0;
		}
	return 0;
}