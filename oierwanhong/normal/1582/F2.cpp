#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<bitset>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
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
const int MAXN = 5011,B = 85;
typedef std::bitset<(1<<13)> bits;
bits a[MAXN],nxt[MAXN],res;
std::vector<short>seq[MAXN];
int main()
{
	int n=read();
	for(int i=0;i<=5000;++i)nxt[i][0]=1,seq[i].emplace_back(0);
	a[0][0]=1;
	while(n--)
	{
		int x=read();
		for(auto y:seq[x])
		{
			int k=y^x;
			a[x][k]=1;
			for(int i=x+1;i<=5000;++i)
				if(!nxt[i][k])nxt[i][k]=1,seq[i].emplace_back(k);
				else break;
		}
		seq[x].clear();
	}
	for(int i=0;i<=5000;++i)res|=a[i];
	printf("%d\n",int(res.count()));
	for(int i=0;i<(1<<13);++i)
		if(res[i])printf("%d ",i);
	puts("");
	return 0;
}