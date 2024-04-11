#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
double x,t;
int n,cnt;
V<P<double,int> > ans;
signed main(){
	scanf("%lld",&n);
	FOR(i,1,n){
		scanf("%lf",&x);
		cnt=1;t=x;
		while(ans.size()&&ans.back().F/ans.back().S>=t/cnt){
			cnt=cnt+ans.back().S;t=t+ans.back().F;
			ans.pop_back();
		}
		ans.PB(MP(t,cnt));
	}
	for(auto u:ans){
		FOR(i,1,u.S){
			printf("%.15f\n",u.F/u.S);
		}
	}
	RE 0;
}