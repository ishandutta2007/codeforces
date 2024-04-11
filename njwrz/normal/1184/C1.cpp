#include<bits/stdc++.h>
using namespace std;
int inf = 1<<30;
int n;
int x[501], y[501];
bool judge(int t) {
	int by = inf, ty = -inf, lx = inf, rx = -inf;
	for(int i = 1; i <= n; ++i)
		if(i != t) {
			by = min(by, y[i]);
			ty = max(ty, y[i]);
			lx = min(lx, x[i]);
			rx = max(rx, x[i]);
		}
	bool flag = 1;
	for(int i = 1; i <= n; ++i)
		if(i != t) {
			if(x[i]!=lx && x[i]!=rx && y[i]!=by && y[i]!=ty) {
				flag = 0;
				break;
			}
		}
	if(flag && ty-by==rx-lx) return true;
	else return false;
}
int main() {
	cin >> n;
	n = 4*n+1;
	for(int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];
	for(int i = 1; i <= n; ++i) {
		if(judge(i)) {
			cout << x[i] << " " << y[i];
			break;
		}
	}
	return 0;
}