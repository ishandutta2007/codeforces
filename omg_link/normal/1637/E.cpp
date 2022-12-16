#include <stdio.h>
#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#include <set>
#define MN 300000

using std::max;
using std::swap;
using std::sort;
using std::greater;
using std::set;
using std::vector;
using std::map;

using pii = std::pair<int,int>;
using ll = long long;

int n,m,a[MN+5];
set<pii> ban;
map<int,int> cnt;
map<int,vector<int>> vals;

ll solve(int cnt,const vector<int>& v1,const vector<int>& v2){
	int msum = 0;
	for(auto x:v1){
		if(x+v2[0]<=msum) break;
		for(auto y:v2){
			pii p = {x,y};
			if(x>y) swap(p.first,p.second);
			if(x==y||ban.count(p)) continue;
			msum = max(msum,x+y);
			break;
		}
	}
	return (ll)msum*cnt;
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ban.insert({x,y});
	}
	for(auto p:cnt){
		vals[p.second].push_back(p.first);
	}
	for(auto& p:vals){
		sort(p.second.begin(),p.second.end(),greater<int>());
	}
	ll ans = 0;
	for(const auto& p1:vals){
		for(const auto& p2:vals){
			if(p2.first>p1.first) continue;
			ans = max(ans,solve(p1.first+p2.first,p1.second,p2.second));
		}
	}
	printf("%lld\n",ans);
	ban.clear();
	cnt.clear();
	vals.clear();
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}