#include <stdio.h>
#include <algorithm>
#include <vector>
#define MN 1000000

using std::vector;
using std::sort;
using std::abs;

using ll = long long;

int n,m;
int a[MN+5];
vector<int> e[MN+5];

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int g = 0;
	for(int i=1;i<=m;i++){
		int b;
		scanf("%d",&b);
		g = gcd(g,b);
	}
	if(g==1){
		ll ans = 0;
		for(int i=1;i<=n;i++){
			ans += abs(a[i]);
		}
		printf("%lld\n",ans);
	}else{
		ll s0 = 0;
		for(int i=1;i<=n;i++){
			e[i%g].push_back(a[i]);
		}
		ll ans = 0;
		for(int i=0;i<g;i++){
			if(e[i].size()==0) continue;
			int cnt = 0;
			for(int& x:e[i]){
				if(x<0){
					cnt++;
					x = -x;
				}
				ans += x;
			}
			sort(e[i].begin(),e[i].end());
			ans -= e[i][0];
			if(cnt&1){
				s0 -= e[i][0];
			}else{
				s0 += e[i][0];
			}
			e[i].clear();
		}
		ans += abs(s0);
		printf("%lld\n",ans);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}