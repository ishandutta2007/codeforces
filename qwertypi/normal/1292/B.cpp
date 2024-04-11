#include <bits/stdc++.h>
#pragma optimize("O2")
#define int long long
#define IOS cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
using namespace std;
typedef long long ll;

int X[64][2];

int cnt = 0;

int xs, ys, t;

int dis(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int f(int i, int upd){
	int d = 0;
	int res = 0;
	int x = xs, y = ys;
	while(d <= t && i >= 0 && i < cnt){
		if(d + dis(x, y, X[i][0], X[i][1]) <= t){
			d += dis(x, y, X[i][0], X[i][1]);
			res++;
			x = X[i][0];
			y = X[i][1];
			i += upd;
		}else{
			return res;
		}
	}
	return res;
}

int32_t main(){
	IOS;
	int x0, y0, a1, a2, b1, b2;
	cin >> x0 >> y0 >> a1 >> a2 >> b1 >> b2;
	cin >> xs >> ys >> t;
	X[0][0] = x0;
	X[0][1] = y0;
	for(int i = 1; i <= 60; i++){
		if(X[i - 1][0] * a1 + b1 > 20000000000000000LL){
			cnt = i;
			break;
		}
		if(X[i - 1][1] * a2 + b2 > 20000000000000000LL){
			cnt = i;
			break;
		}
		X[i][0] = (X[i - 1][0] * a1) + b1;
		X[i][1] = (X[i - 1][1] * a2) + b2;
	}
	int ans = 0;
	for(int i = 0; i < cnt; i++){
		ans = max(ans, f(i, -1));
		ans = max(ans, f(i, 1));
	}
	cout << ans << endl;
	return 0;
}