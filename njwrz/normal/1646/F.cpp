#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int cnt[105][105];
int n,m;
int a[105];
V<V<int> > ans;
void go(){
	V<int> now;
	rep(i,0,n){
		cnt[i][a[i]]--;
		cnt[(i+1)%n][a[i]]++;
		now.PB(a[i]+1);
	}
	ans.PB(now);
}
bool vis[105];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	rep(i,0,n){
		FOR(j,1,n){
			int x;
			cin>>x;x--;cnt[i][x]++;
		}
	}
	rep(i,0,(n-1)*(n-1)){
		rep(j,0,n){
			a[j]=-1;
			rep(k,0,n)if(cnt[j][k]>1){
				a[j]=k;break;
			}
		}
		rep(j,0,n)if(a[(j+1)%n]==-1&&a[j]!=-1){
			a[(j+1)%n]=a[j];
		}
		rep(j,0,n)if(a[(j+1)%n]==-1&&a[j]!=-1){
			a[(j+1)%n]=a[j];
		}
		if(a[0]==-1)break;
		go();
	}
	rep(i,0,n){
		rep(j,0,i){
			rep(k,0,n){
				int t=(i-j+k+n)%n;
				a[k]=t;
			}
			go();
		}
	}
	cout<<ans.size()<<'\n';
	for(auto tv:ans){
		for(auto u:tv)cout<<u<<' ';
		cout<<'\n';
	}
	RE 0;
}