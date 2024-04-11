#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef pair < int, int > pii;

const int OFF = (1 << 23);
const int DOD = (1 << 22);

int tour[2 * OFF], prop[2 * OFF], n, r;
vector < pair < pii, pii > > v;

void refresh(int i){
	if(!prop[i]) return;
	tour[i] += prop[i];
	if(i < OFF){
		prop[2 * i] += prop[i];
		prop[2 * i + 1] += prop[i];
	}
	prop[i] = 0;
}

void update(int i,int a,int b,int lo,int hi,int x){
	refresh(i);
	if(lo <= a && b <= hi){
		prop[i] += x; refresh(i);
		return;
	}
	if(a > hi || b < lo) return;
	update(2 * i, a, (a + b) / 2, lo, hi, x);
	update(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, x);
	tour[i] = max(tour[2 * i], tour[2 * i + 1]);
}

int main(){
	scanf("%d%d", &n, &r);
	for(int i = 0;i < n;i++){
		int xx, yy; scanf("%d%d", &xx, &yy);
		int x = xx + yy;
		int y = xx - yy;
		v.PB({{x - r, 0}, {y - r + DOD, y + r + DOD}});
		v.PB({{x + r, 1}, {y - r + DOD, y + r + DOD}});
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i = 0;i < 2 * n;i++){
		update(1, 0, OFF - 1, v[i].Y.X, v[i].Y.Y, 1 - 2 * v[i].X.Y);
		ans = max(ans, tour[1]);
	}
	printf("%d\n", ans);
	return 0;
}