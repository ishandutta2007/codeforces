//sobskdrbhvk
//remember the flying, the bird dies ):(
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL a, b, c, d;
	cin >> a >> b >> c >> d;
	c = min(c, d);
	LL ans = 0;
	for(LL i = 0; i <= b and i <= a; i++)
		smax(ans, i * 32 + min(c, a - i) * 256);
	cout << ans << '\n';
	return 0;
}