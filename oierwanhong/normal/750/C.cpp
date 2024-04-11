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
int main()
{
	int n=read(),up=1e9,dn=-1e9,sum=0;
	for(int i=1;i<=n;++i)
	{
		int k=read(),d=read();
		if(d==1)umax(dn,1900-sum);
		else umin(up,1899-sum);
		sum+=k;
	}
	if(dn>up){puts("Impossible");return 0;}
	if(up>int(8e8)){puts("Infinity");return 0;}
	printf("%d\n",up+sum);
	return 0;
}