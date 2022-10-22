#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
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
int cnt[26];
char a[2000011];
int main()
{
	int task=read();
	while(task--)
	{
		memset(cnt,0,sizeof cnt);
		scanf("%s",a+1);
		int n=strlen(a+1);
		for(int i=1;i<=n;++i)++cnt[a[i]-'a'];
		for(int i=1;i<=n;++i)
			if(!--cnt[a[i]-'a'])
			{
				puts(a+i);break;
			}
	}
	return 0;
}