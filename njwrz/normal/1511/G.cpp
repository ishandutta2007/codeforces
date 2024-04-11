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
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
int n,m;
int f[200005],p[200005][20],siz[200005][20],sum[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n){
		int x;
		cin>>x;
		f[x]^=1;
		sum[x]^=1;
	}
	FOR(i,1,m)sum[i]+=sum[i-1];
	FOR(i,1,m){
		if(f[i])siz[i][0]=1;
	}
	FOR(i,1,19){
		FOR(j,1,m)if(j+(1<<i)-1<=m){
			siz[j][i]=siz[j][i-1]+siz[j+(1<<(i-1))][i-1];
			p[j][i]=p[j][i-1]^p[j+(1<<(i-1))][i-1];
			if(siz[j+(1<<(i-1))][i-1]&1){
				p[j][i]^=(1<<(i-1));
			}
		}
	}
	int q;
	cin>>q;
	FOR(i,1,q){
		int l,r;
		cin>>l>>r;
		int ans=0,now=0,len=sum[r]-sum[l-1];
		for(int j=19;j>=0;j--)if(l+(1<<j)-1<=r){
			int ns=siz[l][j];
			len-=ns;
			if(len&1){
				ans^=(1<<j);
			}
			ans^=p[l][j];
			l+=(1<<j);
		}
		if(!ans){
			cout<<'B';
		}else cout<<'A';
	}
	RE 0;
}