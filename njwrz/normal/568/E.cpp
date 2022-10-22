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
int dp[200005],a[100005],b[100005],fir[100005],num[100005],p[100005],ite[100005],lst[100005];
V<int> g[200005]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	V<int> v;
	FOR(i,1,n){
		cin>>a[i];if(a[i]!=-1)v.PB(a[i]);
	}
	int m;
	cin>>m;
	FOR(i,1,m)cin>>b[i],v.PB(b[i]);
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	FOR(i,1,n)if(a[i]!=-1)a[i]=lwb(ALL(v),a[i])-v.begin()+1;
	FOR(i,1,m)b[i]=lwb(ALL(v),b[i])-v.begin()+1;
	sort(b+1,b+m+1);
	int cnt=0,l=v.size();
	FOR(i,1,l)dp[i]=1e9;
	FOR(i,1,n){
		if(a[i]==-1){
			int it=0;
			int to=cnt;
			FOR(j,1,l)p[j]=1e9;
			FOR(j,1,m){
				while(it<=cnt&&b[j]>dp[it])it++;
				if(p[it]<b[j])continue;
				p[it]=b[j];ite[it]=i;
				gmax(to,it);gmax(num[i],it);
			}
			FOR(j,1,l)gmin(dp[j],p[j]);
			cnt=to;
		}else{
			int it=lwb(dp+1,dp+cnt+1,a[i])-dp;
			dp[it]=a[i];num[i]=it;lst[i]=ite[it-1];ite[it]=i;
			gmax(cnt,it);
			g[num[i]].PB(i);
		}
		if(!fir[cnt])fir[cnt]=i;
	}
	V<int> s,res;
	FOR(i,1,m)s.PB(b[i]);
	int ans=0;
	FOR(i,1,l){
		if(!fir[i])break;
		ans++;
	}
	int it=fir[ans],ls=1e9,now=ans;
	while(it){
		if(a[it]==-1){
			while(s.back()>=ls){
				res.PB(s.back());
				s.pop_back();
			}
			a[it]=s.back();s.pop_back();
			ls=a[it];
			if(now==1)break;
			bool ff=0;
			for(auto u:g[now-1]){
				if(u>=it)break;
				if(a[u]<a[it]){
					it=u;ff=1;
				}
			}
			if(!ff)for(int j=it-1;j>=0;j--){
				if(a[j]==-1){
					it=j;break;
				}
			}
		}else{
			if(ls<=a[it])RE 0;
//			cout<<ls<<' '<<a[it]<<'\n';
			ls=a[it];
			it=lst[it];
		}
		now--;
	}
	for(auto u:s)res.PB(u);
	FOR(i,1,n){
		if(a[i]==-1){
			a[i]=res.back();
			res.pop_back();
		}
	}
	FOR(i,1,n)cout<<v[a[i]-1]<<' ';
//	FOR(i,1,n)cout<<a[i]<<' ';
	RE 0;
}