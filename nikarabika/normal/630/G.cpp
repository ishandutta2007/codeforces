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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL n;
	cin >> n;
	LL val1 = n * (n + 1) * (n + 2) / 6;
	LL val2 = val1 * (n + 3) / 4 * (n + 4) / 5;
	cout << val1 * val2 << endl;
	return 0;
}