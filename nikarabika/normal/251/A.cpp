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

const int maxn = 1e5 + 10;
int a[maxn],
	n, d;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ptr = 0;
	LL ans = 0;
	for(int i = 0; i < n; i++){
		while(ptr < n and a[ptr] - a[i] <= d) ptr++;
		LL cnt = ptr - i - 1;
		ans += cnt * (cnt - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}