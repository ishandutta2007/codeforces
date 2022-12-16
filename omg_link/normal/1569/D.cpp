#include <stdio.h>
#include <algorithm>
#include <vector>
#define MN 200000
typedef long long ll;

using std::lower_bound;
using std::sort;
using std::vector;

int n,m,k,x[MN+5],y[MN+5];
vector<int> cx[MN+5],cy[MN+5];

void solve(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);
		cx[i].clear();
	}
	for(int i=0;i<m;i++){
		scanf("%d",&y[i]);
		cy[i].clear();
	}
	while(k--){
		int px,py;
		scanf("%d%d",&px,&py);
		int ix = lower_bound(x,x+n,px)-x;
		int iy = lower_bound(y,y+m,py)-y;
		if(x[ix]==px&&y[iy]==py) continue;
		if(x[ix]==px) cy[iy].push_back(ix);
		if(y[iy]==py) cx[ix].push_back(iy);
	}
	ll ans = 0;
	for(int i=1;i<n;i++){	
		ans += (ll)cx[i].size()*(cx[i].size()-1)/2;
		int cnt = 0;
		int lst = -1;
		sort(cx[i].begin(),cx[i].end());
		for(int x:cx[i]){
			if(x==lst){
				ans -= cnt;
				cnt++;
			}else{
				lst = x;
				cnt = 1;
			}
		}
	}
	for(int i=1;i<m;i++){
		ans += (ll)cy[i].size()*(cy[i].size()-1)/2;
		int cnt = 0;
		int lst = -1;
		sort(cy[i].begin(),cy[i].end());
		for(int x:cy[i]){
			if(x==lst){
				ans -= cnt;
				cnt++;
			}else{
				lst = x;
				cnt = 1;
			}
		}
	}
	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}