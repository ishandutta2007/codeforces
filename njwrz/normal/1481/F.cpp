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
int n,x,d[100005],s[100005];
int dp[100005],f[100005],lst[100005],maxi;
V<int> v[100005],it[100005],val[100005];
void dfs(int x) {
	it[d[x]].PB(x);
	gmax(maxi,d[x]);
	for(auto u:v[x]) {
		d[u]=d[x]+1;
		dfs(u);
	}
}
bool ans[100005];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>x;
	FOR(i,2,n) {
		int fa;
		cin>>fa;
		v[fa].PB(i);
	}
	d[1]=1;
	dfs(1);
	FOR(i,1,n) {
		if(!it[i].empty())s[it[i].size()]++,val[it[i].size()].PB(i);
	}
	dp[0]=1;
	FOR(t,1,x) {
		if(!s[t])continue;
		FILL(f,0);
		FOR(i,t,x) {
			if(!dp[i]&&dp[i-t]&&f[i-t]<s[t]) {
				f[i]=f[i-t]+1;
				dp[i]=1;
				lst[i]=val[t][f[i]-1];
			}
		}
	}
	if(dp[x]) {
		int now=x;
		while(now) {
			for(auto u:it[lst[now]])ans[u]=1;
			now=now-it[lst[now]].size();
		}
		cout<<maxi<<'\n';
		FOR(i,1,n) {
			if(ans[i]) {
				cout<<'a';
			} else cout<<'b';
		}
	} else {
		int res=n;
		FOR(i,1,n) {
			if(x>it[i].size()) {
				x-=it[i].size();
				for(auto u:it[i])ans[u]=1;
			} else if(res-x>it[i].size()){
				
			}else {
				int nowc=0,nowt=0;
				for(auto u:it[i]) {
					if(!v[u].empty()) {
						nowc++;
					} else nowt++;
				}
				if(x<=nowt||x>=nowc) {
					if(x>=nowc)for(auto u:it[i]) {
							if(!v[u].empty()) {
								ans[u]=1;
								x--;
							}
						}
					for(auto u:it[i]) {
						if(x&&v[u].empty()) {
							ans[u]=1;
							x--;
						}
					}
				}else{
					x=res-x;
					FOR(j,i,n)for(auto u:it[j])ans[u]=1;
					if(x>=nowc)for(auto u:it[i]) {
							if(!v[u].empty()) {
								ans[u]=0;
								x--;
							}
						}
					for(auto u:it[i]) {
						if(x&&v[u].empty()) {
							ans[u]=0;
							x--;
						}
					}
				}
				break;
			}
			res-=it[i].size();
		}
		cout<<maxi+1<<'\n';
		FOR(i,1,n) {
			if(ans[i]) {
				cout<<'a';
			} else cout<<'b';
		}
	}
	RE 0;
}