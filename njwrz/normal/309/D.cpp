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
int p[100005],p3[100005]; 
int q3(int x){
	RE x>0?p3[x]:p3[-x];
}
int q(int x){
	RE x>0?p[x]:p[-x];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	FOR(i,1,1e5){
		p[i]=i*i;
		p3[i]=3*i*i;
	}
	int n,m,ans=0;
	cin>>n>>m;
	FOR(i,m+1,n-m){
		int l=m+1,r=n-m;
		for(int j=n-m;j>=i;j--){
			int t=q3(j-i)+q(i+j);
			while(r>=l&&q3(n+1-j)+q(n+1-l-l-i)+q3(n+1-i)+q(n+1-l-l+j)>=t)l++;
			while(r>=l&&q3(n+1-j)+q(n+1-(n+1-r)-(n+1-r)-j)+q3(n+1-i)+q(n+1-(n+1-r)-(n+1-r)+i)>=t)r--;
			if(l>r)break;
			ans=ans+(r-l+1)+(i==j?0:(r-l+1));
		}
	}
	cout<<ans*3;
	RE 0;
}