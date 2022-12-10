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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 2e5 + 85 - 69;
LL pos[maxn], n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		pos[x] = i;
	}
	LL ans = 0;
	for(int i = 1; i < n; i++)
		ans += abs(pos[i] - pos[i + 1]);
	cout << ans << endl;
	return 0;
}