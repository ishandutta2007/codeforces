#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
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
const int MAXN = 100011;
int f[MAXN][555];
int main()
{
	int n=read();
	memset(f[0],0x3f,sizeof f[0]);
	f[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		memcpy(f[i],f[i-1],sizeof f[i]);
		int x=read();
		for(int s=0;s<512;++s)
			if(f[i-1][s]<x)umin(f[i][s^x],x);
	}
	std::vector<int>res;
	for(int s=0;s<512;++s)
		if(f[n][s]<512)res.push_back(s);
	printf("%d\n",int(res.size()));
	for(auto x:res)printf("%d ",x);
	puts("");
	return 0;
}