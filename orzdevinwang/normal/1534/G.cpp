#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7;
int n;
ll ns; 
struct pr {
	int x, y;
} p[N];
multiset < int > up, dw;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	cin >> n;
	L(i, 1, n) cin >> p[i].x >> p[i].y;
	sort(p + 1, p + n + 1, [&] (pr a, pr b) { return a.x + a.y < b.x + b.y; });
	L(i, 1, n) {
		ns += p[i].x;
		int L = p[i].x + p[i].y, mxu = i == 1 ? -1e9 : *up.rbegin(), mnd = i == 1 ? 1e9 : L - *dw.rbegin();
		if(mxu <= p[i].x && p[i].x <= mnd) {
			up.insert(p[i].x), dw.insert(p[i].y);
		}
		else if(p[i].x < mxu) {
			up.erase(up.lower_bound(mxu)), dw.insert(L - mxu), up.insert(p[i].x), up.insert(p[i].x);
		}
		else {
			dw.erase(dw.lower_bound(L - mnd)), up.insert(mnd), dw.insert(p[i].y), dw.insert(p[i].y);
		}
	}
	for(const int &x : up) ns -= x;
	cout << ns << "\n";
	return 0;
}