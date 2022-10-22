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
int g[305][100005],s[100005],m[100005],r[100005],ans,uj[100005],u[405],now,B=350;
void uuj(int x){
	ans+=min(m[x],s[x]+(now-uj[x])*r[x]);
	uj[x]=now;u[x/B]=-1;s[x]=0;
}
void jj(int x){
	if(u[x]==-1){
		rep(i,x*B,(x+1)*B)uuj(i);
	}else{
		ans+=g[x][min(100000ll,now-u[x])];
	}
	u[x]=now;
}
void pu(int x){
	if(u[x]!=-1){
		rep(i,x*B,(x+1)*B)uj[i]=u[x];
		u[x]=-1;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,mx=1e5+3;
	cin>>n;
	FOR(i,0,400)u[i]=-1;
	rep(i,0,n){
		cin>>s[i]>>m[i]>>r[i];
		if(!r[i])continue;
		g[i/B][1]+=r[i];
		g[i/B][m[i]/r[i]+1]-=r[i]-m[i]%r[i];
		g[i/B][m[i]/r[i]+2]-=m[i]%r[i];
		uj[i]=0;
	}
	FOR(i,0,(n-1)/B){
		FOR(j,1,mx)g[i][j]+=g[i][j-1];
		FOR(j,1,mx)g[i][j]+=g[i][j-1];
	}
	int q;
	cin>>q;
	FOR(_,1,q){
		int L,R;
		cin>>now>>L>>R;
		L--;R--;
		ans=0;
		pu(L/B);
		pu(R/B); 
		if(R/B==L/B){
			FOR(i,L,R)uuj(i);
		}else{
			while(L%B!=0){
				uuj(L);
				L++;
			}
			while((R+1)%B!=0){
				uuj(R);
				R--;
			}
			FOR(i,L/B,R/B)jj(i);
		}
		cout<<ans<<'\n';
	}
	RE 0;
}