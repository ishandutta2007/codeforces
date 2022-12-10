//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e3 + 85 - 69;
int h[maxn],
	n,
	ans = 1000 * 1000 * 1000,
	stans, dans;

int saghf(int x){
	return (x + 1) / 2;
}

int kaf(int x){
	if(x % 2 == 0) return x / 2;
	if(x > 0) return x / 2;
	return (x - 1) / 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> h[i];
	sort(h, h + n);
	for(int d = 0; d <= 20000; d++){
		int mn = +1000000 * 1000,
			mx = -1000000 * 1000;
		for(int i = 0; i < n; i++){
			smin(mn, h[i] - i * d);
			smax(mx, h[i] - i * d);
		}
		if(saghf(mx - mn) < ans){
			ans = saghf(mx - mn);
			stans = kaf(mx + mn);
			dans = d;
		}
	}
	cout << ans << '\n'
		<< stans << ' ' << dans << '\n';
	return 0;
}