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

const int MAXN = 600011;
int a[MAXN],cnt[MAXN],n,m;
int b[MAXN];
bool vis[MAXN];
std::vector<int>seq;
int main()
{
	int task=read();
	while(task--)
	{
		seq.clear();
		n=read(),m=read();
		for(int i=0;i<n;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			int k=(i-a[i]+n)%n;
			++cnt[k];
		}
		for(int k=0;k<n;++k)
			if(cnt[k]>= n/3)
			{
				for(int i=1;i<=n;++i)b[i]=(a[i]+k-1)%n+1,vis[i]=0;
				int res=0;
				for(int i=1;i<=n;++i)
					if(!vis[i])
					{
						int p=b[i],cur=0;
						while(p!=i)vis[p]=1, p=b[p],++cur;
						vis[i]=1;
						res+=cur;
					}
				if(res<=m)seq.push_back(k);
			}
		printf("%d",int(seq.size()));
		for(auto x:seq)printf(" %d",x);
		puts("");
	}
	return 0;
}