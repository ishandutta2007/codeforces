//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5 + 10;
LL l[maxn], r[maxn], bad[maxn];
LL n, p;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> p;
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
		l[i]--;
		bad[i] = (r[i] - l[i]) - (r[i] / p - l[i] / p);
	}
	LD ans = LD(n);
	for(int i = 0; i + 1 < n; i++)
		ans -= (LD(bad[i]) / LD(r[i] - l[i])) * (LD(bad[i + 1]) / LD(r[i + 1] - l[i + 1]));
	ans -= (LD(bad[n - 1]) / LD(r[n - 1] - l[n - 1])) * (LD(bad[0]) / LD(r[0] - l[0]));
	cout.precision(10);
	cout << fixed << ans * LD(2000) << endl;
	return 0;
}