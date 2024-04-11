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

int p;
LL n, t;

LL C(LL m, LL r){
	smin(r, m - r);
	if(r < 0) return 0;
	LL ret = 1;
	for(LL i = 1; i <= r; i++)
		ret = ret * (m - i + 1) / i;
	return ret;
}

LL build(int pos, int put = 0){
	if(pos == -1)
		return __builtin_popcountll(n) == p;
	LL ret = 0;
	if((n >> pos) & 1LL)
		ret = C(pos, p - put);
	return ret + build(pos - 1, put + ((n>>pos)&1LL));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t;
	n++;
	t *= 2;
	if(t & (t - 1)){
		cout << 0 << '\n';
		return 0;
	}
	for(p = 0; t >> p; p++);
	p--;
	LL ans = build(60) - (p == 1);
	cout << ans << '\n';
	return 0;
}