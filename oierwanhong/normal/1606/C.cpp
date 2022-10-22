#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
typedef unsigned un;
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/

int pw[10];
int main()
{
	pw[0]=1;
	for(int i=1;i<10;++i)pw[i]=pw[i-1]*10;
	int task=read();
	while(task--)
	{
		int n=read(),k=read()+1;
		int x=read(),ans=0;
		if(n==1)
		{
			printf("%d\n",k);continue;
		}
		for(int i=2;i<=n;++i)
		{
			int y=read();
			if(k>=pw[y-x]-1)k-=pw[y-x]-1,ans+=(pw[y-x]-1)*pw[x];
			else ans+=k*pw[x],k=0;
			x=y;
		}
		if(k)printf("%d",k);
		printf("%d\n",ans);
	}
	return 0;
}