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

const int maxn = 85 + 85 - 69 + 1;
int a[maxn], b[maxn],
	n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if(m > n)
		return cout << "0/1", 0;
	for(int i = 0; i <= n; i++)
		cin >> a[i];
	for(int i = 0; i <= m; i++)
		cin >> b[i];
	cout << (a[0] / abs(a[0]) == b[0] / abs(b[0]) ? "" : "-");
	if(n > m)
		return cout << "Infinity", 0;
	a[0] = abs(a[0]), b[0] = abs(b[0]);
	cout << a[0] / __gcd(a[0], b[0]) << '/' << b[0] / __gcd(a[0], b[0]);
	return 0;
}