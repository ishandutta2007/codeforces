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

const int maxn = 2000 + 85 - 69;
int n;
LL x[maxn],
   y[maxn];
vector<pair<pll, LL>> segs;

LL Abs(LL x){return x < 0 ? -x : x;}

pll shibof(int i, int j){
	LL dx = x[i] - x[j],
	   dy = y[i] - y[j];
	if(dx == 0)
		return MP(0, 1);
	if(dy == 0)
		return MP(1, 0);
	LL dxp = Abs(dx),
	   dyp = Abs(dy);
	LL gcd = __gcd(dxp, dyp);
	dx /= gcd, dy /= gcd;
	if(dy < 0)
		dx *= -1, dy *= -1;
	return MP(dx, dy);
}

LL distof(int i, int j){
	LL dx = x[i] - x[j];
	LL dy = y[i] - y[j];
	return dx * dx + dy * dy;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++){
			segs.PB(MP(shibof(i, j), distof(i, j)));
			//cout << i << ' ' << j << ' ' << segs.back().L.L << ' ' << segs.back().L.R << ' ' << segs.back().R << endl;
		}
	sort(all(segs));
	LL ans = 0;
	for(int i = 0; i < sz(segs);){
		int ptr = i;
		while(ptr < sz(segs) and segs[i] == segs[ptr]) ptr++;
		LL cnt = ptr - i;
		ans += (cnt * (cnt - 1)) / 2;
		i = ptr;
	}
	cout << ans / 2 << endl;
	return 0;
}