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
/**********/
const int MAXN = 511;
ll cnt[15],pw[15];
int main()
{
	pw[0]=1;
	for(int i=1;i<=12;++i)pw[i]=pw[i-1]*10;
	int task=read();
	while(task--)
	{
		ll s=read(),n=read();
		ll now=0;
		for(int i=0;i<=10;++i)cnt[i]=s%pw[i+1]/pw[i],now+=cnt[i];
		while(now<n)
		{
			for(int i=1;i<=10;++i)
				if(cnt[i])
				{
					--cnt[i],now+=9;
					cnt[i-1]+=10;
					break;
				}
		}
		int cur=0;
		for(int i=0;i<=10;++i)
			while(cnt[i])
			{
				if(cur+1<n)printf("%lld ",pw[i]),--cnt[i],++cur;
				else
				{
					ll sum=0;
					for(int j=i;j<=10;++j)sum+=cnt[j]*pw[j];
					printf("%lld ",sum);
					goto End;
				}
			}
End:
		puts("");
	}
	return 0;
}