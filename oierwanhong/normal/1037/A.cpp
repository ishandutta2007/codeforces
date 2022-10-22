#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void umax(int& a,int t){if(a<t)a=t;}
bool umin(ll& a,ll t){if(a>t)return a=t,1;return 0;}
/**********/
int main()
{
	ll n=read();
	for(int i=1;i<50;++i)
		if((1ll<<i)-1>=n){printf("%d\n",i);return 0;}
	return 0;
}