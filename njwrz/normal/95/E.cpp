//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int siz[100005];
int dp[100005],cnt[100005],fa[100005];
bool vis[100005];
int getfa(int x){
	if(x==fa[x]){
		RE x;
	}else{
		RE fa[x]=getfa(fa[x]);
	}
}
P<int,int> q[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n)siz[i]=1,fa[i]=i;
	FILL(dp,0x3f3f3f3f);
	dp[0]=0;
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		x=getfa(x);
		y=getfa(y);
		if(x!=y){
			fa[x]=y;
			siz[y]+=siz[x];
		}
	}
	FOR(i,1,n)if(!vis[getfa(i)]){
		cnt[siz[getfa(i)]]++;
		vis[getfa(i)]=1;
	}
	FOR(i,1,n)if(cnt[i]){
		for(int j=0;j<i;j++){
			int s=1,t=0;
			for(int k=j;k<=n;k+=i){
				int now=dp[k];
				if(s<=t){
					gmin(dp[k],k/i-q[s].F);
				}
				if(s<=t&&q[t].S==k)s++;
				while(s<=t&&q[t].F<=k/i-now){
					t--;
				}
				q[++t]=MP(k/i-now,k+cnt[i]*i);
			}
		}
	}
	int ans=1e9;
	FOR(i,1,n){
		bool ff=0;
		int t=i;
		while(t){
			if(t%10!=7&&t%10!=4){
				ff=1;break;
			}
			t/=10;
		}
		if(!ff){
			gmin(ans,dp[i]-1);
		}
	}
	if(ans>=1e9){
		cout<<-1;
	}else cout<<ans;
	RE 0;
}