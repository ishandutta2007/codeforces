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
int it[9][6];
int t[505][505],mod=998244353;
int f[54][54]; 
struct matrix{
	int s[505][505],n,m;
	void mul(matrix a){
		FOR(i,1,n){
			FOR(j,1,m){
				FOR(k,1,m){
					t[i][j]=(s[i][k]*a.s[k][j]+t[i][j])%mod;
				}
			}
		}
		FOR(i,1,n)FOR(j,1,m)s[i][j]=t[i][j],t[i][j]=0;
	}
}tx,T;
int m,n,l[9];
char c[9][6];
P<int,int> p[54];
bool check(P<int,int> x,P<int,int> y){
	for(int i=x.S,j=y.S;i<=l[x.F]&&j<=l[y.F];i++,j++){
		if(c[x.F][i]!=c[y.F][j])RE 0;
	}
	RE 1;
}
int k;
int nxt(int i){
	P<int,int> tp=p[i];
	tp.S++;
	if(tp.S==l[tp.F]){
		RE k;
	}else RE it[tp.F][tp.S];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int cnt=0;
	FOR(i,1,n){
		string s;
		cin>>s;
		l[i]=s.size();
		FOR(j,1,l[i])c[i][j]=s[j-1];
		rep(j,1,l[i])it[i][j]=++cnt,p[cnt]=MP(i,j);
	}
	it[0][0]=++cnt;p[cnt]=MP(0,0);
	k=cnt;
	cnt=0;
	FOR(i,1,k){
		FOR(j,i,k){
			if(i==k||j==k||check(p[i],p[j]))f[i][j]=f[j][i]=++cnt;
		}
	}
	rep(i,1,k){
		rep(j,i,k){
			if(f[i][j])tx.s[f[i][j]][f[nxt(i)][nxt(j)]]++;
		}
	}
	tx.n=cnt;
	tx.m=cnt;
	rep(i,1,k){
		FOR(j,1,n){
			if(f[nxt(i)][it[j][1]?it[j][1]:k]&&c[j][1]==c[p[i].F][p[i].S+1]){
				tx.s[f[i][k]][f[nxt(i)][it[j][1]?it[j][1]:k]]++;
			}
		}
	}
	FOR(i,1,n){
		FOR(j,1,n){
			if(c[i][1]==c[j][1]&&f[it[i][1]?it[i][1]:k][it[j][1]?it[j][1]:k]){
				tx.s[f[k][k]][f[it[i][1]?it[i][1]:k][it[j][1]?it[j][1]:k]]++; 
			}
		}
	}
	T.n=1;
	T.m=cnt;
	T.s[1][f[k][k]]=1;
	while(m){
		if(m&1)T.mul(tx);
		tx.mul(tx);
		m/=2;
	}
	cout<<T.s[1][f[k][k]];
	RE 0;
}