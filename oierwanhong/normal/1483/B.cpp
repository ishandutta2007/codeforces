#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 500011;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int nxt[MAXN],a[MAXN],seq[MAXN],res[MAXN];
bool vis[MAXN];
void solve()//attention to n=1!!!
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read(),nxt[i]=(i==n?1:i+1),vis[i]=0;
	int cnt=0,l=0;
	for(int i=1;i<=n;++i)
		if(gcd(a[i],a[nxt[i]])==1)seq[++cnt]=i;
	while(cnt)
	{
		int nl=0;
		for(int w=1;w<=cnt;++w)
		{
			int i=seq[w];
			if(vis[i])continue;
			res[++l]=nxt[i],vis[nxt[i]]=1;
			nxt[i]=nxt[nxt[i]];
			if(gcd(a[i],a[nxt[i]])==1)seq[++nl]=i;
		}
		cnt=nl;
	}
	printf("%d ",l);
	for(int w=1;w<=l;++w)printf("%d ",res[w]);
	puts("");
}
int main()
{
	int task=read();
	while(task--)solve();
	return 0;
}