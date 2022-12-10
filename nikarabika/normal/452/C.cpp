//sobskdrbhvk
//remember the flying, the bird dies ):(
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	LD ans = 0,
	   cur = LD(1) / n;
	for(int i = 0; i < n - 1; i++){
		cur *= LD(n * m - m - i) / (i + 1);
		cur /= LD(n * m - 1 - i) / (i + 1);
	}
	for(int i = 1; i <= m; i++){
		ans += cur;
		cur *= LD(m - i) / i;
		cur *= LD(n - i) / LD(n * m - n - m + i + 1);
		cur *= LD(i + 1) / i;
	}
	cout.precision(15);
	cout << fixed << ans << '\n';
	return 0;
}