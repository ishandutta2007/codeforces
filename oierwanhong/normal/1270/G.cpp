#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void umax(int& a,int t){if(a<t)a=t;}
bool umin(ll& a,ll t){if(a>t)return a=t,1;return 0;}
ll abs(ll x){return x>0?x:-x;}

/**********/
#define MAXN 2000011
int to[MAXN];
bool vis[MAXN],ring[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		for(int i=1;i<=n;++i)to[i]=i-read(),vis[i]=ring[i]=0;
		int p=1;
		while(!vis[p])vis[p]=1,p=to[p];
		std::vector<int>res;
		while(!ring[p])ring[p]=1,res.push_back(p),p=to[p];
		printf("%d\n",int(res.size()));
		for(auto x:res)printf("%d ",x);
		puts("");
	}
	return 0;
}