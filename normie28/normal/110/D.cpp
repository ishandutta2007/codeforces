#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define psp printf(" ")
#define endc printf("\n")
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
 
//const int maxn = 2e5 + 7; 
//const int md = 1e9 + 7;
 
vector<int> lucky;
 
void findall(int k, int n, bool st) {
	if (k == 0) {
		if (st) lucky.pb(n); return;
	}
 
	if (!st) findall(k-1, n, false);
 
	findall(k-1, n*10 + 4, true); findall(k-1, n*10 + 7, true);
}
 
ld li(int x,int l,int r, int dir) {
	if (dir == -1) {
		if (x < l) return 0;
		return min(x - l + 1, r - l + 1);
	}
	if (dir == 1) {
		if (r < x) return 0;
		return min(r - x + 1, r - l + 1);
	}
}
 
int main() {
	findall(9, 0, false);		
	sort(lucky.begin(), lucky.end());
	ll pl, pr, vl, vr; int k; cin>>pl>>pr>>vl>>vr>>k;
 
	ld deno = (pr - pl + 1) * (vr - vl + 1);
	ld ans  = 0.0;
		
	for (int i = 0; i < lucky.size(); i++) {
		int j = i + k - 1;
		if (j >= lucky.size()) continue;
 
		int x = lucky[i], y = lucky[j];
		
		ll cura = 0, curb = 0;
		
		int px, py;
 
		if (i == 0) px = -1;
		else px = lucky[i-1];
 
		if (j == lucky.size()-1) py = (int)(1e9 + 7);
		else py = lucky[j+1];
 
		cura = (li(x, pl, pr, -1) - li(px, pl, pr, -1))*(li(y, vl, vr, 1) - li(py, vl, vr, 1));
		curb = (li(x, vl, vr, -1) - li(px, vl, vr, -1))*(li(y, pl, pr, 1) - li(py, pl, pr, 1));
 
		ans += cura + curb;
 
		if (x == y && pl <= x && x <= pr) ans--;
	}
	
	cout<<setprecision(12)<<fixed<<ans/deno<<endl;
}