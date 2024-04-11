#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/

const int MAXN = 2011;
char s[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		int ans=10;
		int f=0;
		for(int i=1;i<=n;++i)
		{
			if(i&1)f+=s[i]!='0';
			else f-=s[i]=='1';
			if(((n-i+1)>>1)<f){umin(ans,i);break;}
		}
		f=0;
		for(int i=1;i<=n;++i)
		{
			if(i&1)f-=s[i]=='1';
			else f+=s[i]!='0';
			if(((n-i)>>1)<f){umin(ans,i);break;}
		}
		printf("%d\n",ans);
	}
	return 0;
}