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
	#define sz 5050
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
int a[sz],aa[sz];
int dp[3][sz][2],ans[3][sz];

int las2,las1,cur;

void work(int l,int r,int k)
{
	#define upd(x) dp[cur][l][k]=min(dp[cur][l][k],x)
	if (k==0)
	{
		upd(dp[las1][l+1][0]+1);
		upd(dp[las1][l+1][1]+(a[l]==a[r]?0:1));
		if (a[l]==a[r]) upd(ans[las2][l+1]+1);
	}
	else
	{
		upd(dp[las1][l][1]+1);
		upd(dp[las1][l][0]+(a[l]==a[r]?0:1));
		if (a[l]==a[r]) upd(ans[las2][l+1]+1);
	}
	ans[cur][l]=min(ans[cur][l],dp[cur][l][k]);
}

int main()
{
	file();
	read(m);
	rep(i,1,m) read(aa[i]);
	a[n=1]=aa[1];
	rep(i,2,m) if (aa[i]!=aa[i-1]) a[++n]=aa[i];
	memset(dp,0x3f,sizeof(dp));memset(ans,0x3f,sizeof(ans));
	las2=0,las1=1,cur=2;
	rep(i,1,n) dp[cur][i][0]=dp[cur][i][1]=ans[cur][i]=0;
	#define l j
	#define r (i+j-1)
	rep(i,2,n)
	{
		swap(las2,las1);swap(las1,cur);
		rep(j,1,n) dp[cur][j][0]=dp[cur][j][1]=ans[cur][j]=0x3f3f3f3f; 
		rep(j,1,n-i+1)
			rep(k,0,1)
				work(l,r,k);
	}
		
	cout<<ans[cur][1];
	return 0;//
}