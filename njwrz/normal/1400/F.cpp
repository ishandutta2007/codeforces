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
//                       `=---='

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
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
char c[1005];
int k;
int dp[2][1<<20];
int ma[1<<21],cnt,to[1<<20][11],lst[30],td[2][1<<20],tc[2];
bool ch[1<<21],in[1<<20];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%s%d",c+1,&k);
	int n=strlen(c+1);
	bool tf=1;
	FOR(i,1,n){
		int sum=0;
		bool ff=1,cf=1;
		FOR(j,i,n){
			sum+=c[j]-'0';
			if(sum>k)break;
			if(sum==k){
				if(ff)cf=0;
				break;
			}
			int ts=0;
			for(int tt=j;tt>=i;tt--){
				ts+=c[tt]-'0';
				if(k%ts==0){
					ff=0;
				}
			}
		}
		if(!cf){
			tf=0;break;
		}
	}
	if(tf){
		cout<<0;RE 0;
	}
	rep(mk,0,1<<(k+1)){
		if(!(mk&(1<<k))){
			ma[++cnt]=mk;ch[mk]=1;continue;
		}
		bool ff=1;
		int nc=0;
		rep(j,0,k+1)if(mk&(1<<j)){
			FOR(ti,1,nc)if((j-lst[ti]!=k&&k%(j-lst[ti])==0)){
				ff=0;break;
			}
			if(!ff)break;
			lst[++nc]=j;
		}
		if(!ff){
			ma[++cnt]=mk;ch[mk]=1;continue;
		}
	}
	rep(mk,1,1<<k){
		rep(j,1,10){
			int now=(mk<<j)+1;
			now&=(1<<(k+1))-1;
			if(ch[now])to[mk][j]=now&((1<<k)-1);
//			cout<<to[mk][j]<<' ';
		}
//		cout<<'\n';
	}
	int now=1,maxi=0;
	FOR(i,0,1)rep(mk,0,1<<k)dp[i][mk]=-2147483647;
	dp[0][1]=0;
	td[0][++tc[0]]=1;
	FOR(i,1,n){
		now^=1;
		FOR(j,1,tc[now])in[td[now][j]]=0;
		tc[now^1]=0;
//		cout<<dp[now][1]<<' ';
		FOR(j,1,tc[now]){
			int mk=td[now][j];
//			cout<<j<<' ';
			if(to[mk][c[i]-'0']){
				int &tn=dp[now^1][to[mk][c[i]-'0']];
				if(dp[now][mk]+1>=tn){
					tn=dp[now][mk]+1;gmax(maxi,tn);
					if(tn>maxi-k&&!in[to[mk][c[i]-'0']])td[now^1][++tc[now^1]]=to[mk][c[i]-'0'],in[to[mk][c[i]-'0']]=1;
				}
			}
			int &tn=dp[now^1][mk];
			if(dp[now][mk]>=tn){
				tn=dp[now][mk];gmax(maxi,tn);
				if(tn>maxi-k&&!in[mk])td[now^1][++tc[now^1]]=mk,in[mk]=1;
			}
		}
//		cout<<maxi<<'\n';
//		cout<<dp[now^1][1]<<'\n';
	}
	cout<<n-maxi;
	RE 0;
}