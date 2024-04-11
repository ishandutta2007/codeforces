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
#define int long long
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
int n,m,nxt,ans;
char c[35][35];
bool vis[7][7],f[35][35],fv[35][35];
P<int,int> p[30];
int to[35][35];
int col[30];
int a[35][35],b[35][35];
int ct[10];
void dfs(int x){
	if(x==15){
		if(!ans){
			FOR(i,1,14){
				FOR(j,p[i].F,p[i].F+1){
					FOR(k,p[i].S,p[i].S+1){
						a[j][k]=b[j][k];
					}
				}
			}
		}
		ans++;
		RE;
	}
	FOR(i,0,nxt-(nxt==7))if(i==nxt||ct[i]==0){
		V<P<int,int> > vp;
		bool ff=1;
		FOR(j,p[x].F,p[x].F+1){
			FOR(k,p[x].S,p[x].S+1)b[j][k]=i,fv[j][k]=1;
		}
		FOR(j,p[x].F,p[x].F+1){
			FOR(k,p[x].S,p[x].S+1)if(to[j][k]){
				int tj,tk;
				tj=j-(to[j][k]==2)+(to[j][k]==4);
				tk=k-(to[j][k]==1)+(to[j][k]==3);
				if(!fv[tj][tk]||(j>=tj&&k>=tk&&tj>=p[x].F&&tk>=p[x].S))continue;
				if(vis[b[tj][tk]][i]){
					ff=0;break;
				}
				vis[b[tj][tk]][i]=vis[i][b[tj][tk]]=1;
				vp.PB(MP(b[tj][tk],i));
			}
		}
		if(ff){
			if(i!=nxt)ct[i]=1;
			int tn=nxt;
			nxt+=i==nxt;
			dfs(x+1);
			nxt=tn;
			ct[i]=0;
		}
		for(auto u:vp){
			vis[u.F][u.S]=vis[u.S][u.F]=0;
		}
		FOR(j,p[x].F,p[x].F+1){
			FOR(k,p[x].S,p[x].S+1)b[j][k]=0,fv[j][k]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>c[i][j];
		}
	}
	FOR(i,1,n){
		FOR(j,1,m){
			if(c[i][j]!='.'&&(c[i][j]==c[i-1][j]||c[i][j]==c[i][j-1])){
				to[i][j]=1+(c[i][j]==c[i-1][j]);
			}
			if(c[i][j]!='.'&&(c[i][j]==c[i+1][j]||c[i][j]==c[i][j+1])){
				to[i][j]=3+(c[i][j]==c[i+1][j]);
			}
		}
	}
	int cnt=0;
	rep(i,1,n){
		rep(j,1,m){
			if(!f[i][j]&&c[i][j]!='.'&&c[i+1][j]!='.'&&c[i][j+1]!='.'&&c[i+1][j+1]!='.'){
				f[i][j]=f[i+1][j]=f[i][j+1]=f[i+1][j+1]=1;
				p[++cnt]=MP(i,j);
			}
		}
	}
	dfs(1);
	FOR(i,1,7)ans*=i;
	cout<<ans<<'\n';
	FOR(i,1,n){
		FOR(j,1,m){
			if(c[i][j]=='.'){
				cout<<'.';
			}
			else cout<<a[i][j];
		}
		cout<<'\n';
	}
	RE 0;
}