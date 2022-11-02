#include<bits/stdc++.h>
namespace my_std{
	using namespace std;
	#define pii pair<int,int>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define sz 1010101
	typedef long long ll;
	template<typename T>
	inline void read(T& t)
	{
		t=0;char f=0,ch=getchar();
		double d=0.1;
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
		if(ch=='.')
		{
			ch=getchar();
			while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();
		}
		t=(f?-t:t);
	}
	template<typename T,typename... Args>
	inline void read(T& t,Args&... args){read(t); read(args...);}
	void file()
	{
		#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);
		#endif
	}
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,m;
int cnt[sz];
int dp[sz][5][5];

int main()
{
	file();
	int x;
	read(n,m);
	rep(i,1,n) read(x),++cnt[x];
	memset(dp,~0x3f,sizeof(dp));
	dp[0][0][0]=0;
	rep(i,0,min(4,cnt[1])) dp[1][i][0]=(cnt[1]-i)/3;
	rep(i,2,m)
	{
		rep(j,0,4)
		{
			if (j>cnt[i]) break;
			rep(k,0,4)
			{
				if (k>cnt[i-1]) break;
				rep(l,0,2)
				{
					if (j+l>cnt[i]||k+l>cnt[i-1]||l>cnt[i-2]||k+l>4) break;
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][k+l][l]+(cnt[i]-l-j)/3+l);
				}
			}
		}
	}
	cout<<dp[m][0][0];
}