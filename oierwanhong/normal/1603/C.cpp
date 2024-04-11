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
const int MAXN = 300011,INF = 1e9+233,mod = 998244353;
int a[MAXN];
std::vector<pii>cur,nxt;
int main()
{
	int task=read();
	while(task--)
	{
		cur.clear(),nxt.clear();
		int n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		int ans=0;
		for(int i=n;i;--i)
		{
			cur.emplace_back(pii(INF,1)),nxt.clear();
			for(int j=0;j<cur.size();++j)
			{
				int l=(a[i]+cur[j].first-1)/cur[j].first;
				ans=(ans+ll(l-1)*cur[j].second%mod*i)%mod;
				if(nxt.size()&&nxt.back().first== a[i]/l)nxt.back().second+=cur[j].second;
				else nxt.emplace_back(pii(a[i]/l,cur[j].second));
			}
			cur=nxt;
		}
		printf("%d\n",ans);
	}
	return 0;
}