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

const int maxn = 1e5 + 85 - 69;
LD p[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> p[i];
	LD curval = 2 * n - 1,
	   ans = 0;
	for(int i = n - 1; i >= 0; i--){
		ans += (curval - 2 * i) * p[i];
		curval *= p[i];
		curval += (1 - p[i]) * (2 * i - 1);
	}
	cout.precision(15);
	cout << fixed << ans << endl;
	return 0;
}