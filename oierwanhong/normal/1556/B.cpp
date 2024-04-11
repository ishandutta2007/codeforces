#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
const int MAXN = 200011;
int p[2][MAXN],a[MAXN];
int cnt[2];
int main()
{
	int task=read();
	while(task--)
	{
		cnt[0]=cnt[1]=0;
		int n=read(),l1=0,l0=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read()&1;
			++cnt[a[i]],p[a[i]][cnt[a[i]]]=i;
		}
		if(cnt[0]==cnt[1])
		{
			ll ans1=0,ans2=0;
			for(int i=1;i<=cnt[0];++i)ans1+=abs(p[0][i]-(2*i-1)),ans2+=abs(p[0][i]-2*i);
			printf("%lld\n",min(ans1,ans2));
		}
		else if(cnt[0]==cnt[1]+1)
		{
			ll ans1=0,ans2=0;
			for(int i=1;i<=cnt[0];++i)ans1+=abs(p[0][i]-(2*i-1));
			printf("%lld\n",ans1);
		}
		else if(cnt[1]==cnt[0]+1)
		{
			ll ans1=0;
			for(int i=1;i<=cnt[1];++i)ans1+=abs(p[1][i]-(2*i-1));
			printf("%lld\n",ans1);
		}
		else puts("-1");
	}
	return 0;
}