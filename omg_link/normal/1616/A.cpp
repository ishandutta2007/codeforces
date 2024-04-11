#include <stdio.h>
#include <algorithm>
#include <map>

using std::abs;
using std::min;
using std::map;

void solve(){
	map<int,int> cnt;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		cnt[abs(a)]++;
	}
	int ans = 0;
	for(auto p:cnt){
		int limit = p.first==0?1:2;
		ans += min(limit,p.second);
	}
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}