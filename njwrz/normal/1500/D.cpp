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
P<short,short> lu[1505][1505][12],l[1505][1505][12],u[1505][1505][12];
int slu[1505][1505],sl[1505][1505],su[1505][1505]; 
int a[1505][1505];
int ti,tj;
P<int,int> p[35];
bool cmp(P<int,int> x,P<int,int> y){
	RE max(ti-x.F,tj-x.S)<max(ti-y.F,tj-y.S);
}
int ans[1505];
bool vis[1505*1505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;k++;
	FOR(i,1,n){
		FOR(j,1,n){
			cin>>a[i][j];
		}
	}
	FOR(i,1,n){
		FOR(j,1,n){
			l[i][j][++sl[i][j]]=MP(i,j);
			FOR(b,1,sl[i][j-1]){
				if(a[l[i][j-1][b].F][l[i][j-1][b].S]==a[i][j]){
					
				}else l[i][j][++sl[i][j]]=l[i][j-1][b];
			}
			gmin(sl[i][j],k);
		}
	}
	FOR(j,1,n){
		FOR(i,1,n){
			u[i][j][++su[i][j]]=MP(i,j);
			FOR(b,1,su[i-1][j]){
				if(a[u[i-1][j][b].F][u[i-1][j][b].S]==a[i][j]){
					
				}else u[i][j][++su[i][j]]=u[i-1][j][b];
			}
			gmin(su[i][j],k);
		}
	}
	FOR(i,1,n){
		FOR(j,1,n){
			ti=i;tj=j;
			int len=0;
			p[++len]=MP(i,j);
			FOR(b,1,su[i-1][j]){
				p[++len]=u[i-1][j][b];
			}
			FOR(b,1,sl[i][j-1]){
				p[++len]=l[i][j-1][b];
			}
			FOR(b,1,slu[i-1][j-1]){
				p[++len]=lu[i-1][j-1][b];
			}
			sort(p+1,p+len+1,cmp);
			FOR(b,1,len){
				if(!vis[a[p[b].F][p[b].S]])lu[i][j][++slu[i][j]]=p[b];
				if(slu[i][j]==k)break;
				vis[a[p[b].F][p[b].S]]=1; 
			}
			FOR(b,1,len)vis[a[p[b].F][p[b].S]]=0;
			if(slu[i][j]==k)ans[min(max(i-lu[i][j][slu[i][j]].F,j-lu[i][j][slu[i][j]].S),min(i,j))]++;
			else ans[min(i,j)]++;
//			cout<<i-lu[i][j][slu[i][j]].F<<' '<<j-lu[i][j][slu[i][j]].S<<' ';
		}
//		cout<<'\n';
	} 
	for(int i=n;i>=1;i--)ans[i]+=ans[i+1];
	FOR(i,1,n)cout<<ans[i]<<'\n';
	RE 0;
}