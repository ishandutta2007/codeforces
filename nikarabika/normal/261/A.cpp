//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
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
int a[maxn],
	ans, n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int mn = 1000000;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		smin(mn, x);
	}
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for(int i = n - 1; i >= 0; i-=mn+2)
		for(int j = 0; j < mn; j++)
			if(i - j >= 0)
				ans += a[i - j];
	cout << ans << '\n';
	return 0;
}