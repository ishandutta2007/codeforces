#include <cstdio>
#include <vector>
#include <algorithm>

#define PB push_back

using namespace std;

typedef long long ll;

vector < int > vx, vy;
int n;

void solve(){
	vx.clear(); vy.clear();
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		int x, y; scanf("%d%d", &x, &y);
		vx.PB(x), vy.PB(y);
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	if(n & 1)
		printf("1\n");
	else
		printf("%lld\n", (ll)(vx[n / 2] - vx[n / 2 - 1] + 1) * (vy[n / 2] - vy[n / 2 - 1] + 1));
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
}