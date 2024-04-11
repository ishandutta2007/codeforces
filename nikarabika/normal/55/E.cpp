#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef complex<LD> point;

#define x real()
#define y imag()

const int maxn = 1e5 + 85 - 69;
point a[maxn];
LL n, t;

LD cross(point A, point B){
	return A.x * B.y - A.y * B.x;
}

bool sign(LD val){
	return val < 0;
}

void solve(point P){
	for(int i = 0; i + 1 < n; i++){
		if(sign(cross(a[i + 1] - a[i], P - a[i])) != sign(cross(a[0] - a[n - 1], P - a[n - 1]))){
			cout << 0 << '\n';
			return;
		}
	}
	LL ans = 0;
	for(int i = 0; i < n; i++){
		int lo = i + 1, hi = n + i - 1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(cross(a[mid % n] - a[i], P - a[i]) < 0)
				lo = mid;
			else
				hi = mid;
		}
		LL len = lo - i;
		ans += len * (len - 1) / 2;
	}
	cout << n * (n - 1) * (n - 2) / 6 - ans << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		a[i] = point(fi, se);
	}
	cin >> t;
	while(t--){
		int fi, se;
		cin >> fi >> se;
		solve(point(fi, se));
	}
	return 0;
}