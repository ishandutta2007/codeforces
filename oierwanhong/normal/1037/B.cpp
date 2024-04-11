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
#define MAXN 500011
int a[MAXN];
int main()
{
	int n=read(),s=read(),mid=(n+1)>>1;
	for(int i=1;i<=n;++i)a[i]=read();
	std::sort(a+1,a+n+1);
	if(a[mid]==s){puts("0");return 0;}
	else if(a[mid]<s)
	{
		ll ans=0;
		for(int i=mid;i<=n;++i)
			if(a[i]<s)ans+=s-a[i];
			else break;
		printf("%lld\n",ans);
	}
	else
	{
		ll ans=0;
		for(int i=mid;i;--i)
			if(a[i]>s)ans+=a[i]-s;
			else break;
		printf("%lld\n",ans);
	}
	return 0;
}