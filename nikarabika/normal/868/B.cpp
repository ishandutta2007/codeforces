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

bool f(LD s, LD e, LD p) {
	if (s <= e)
		return s <= p and p <= e;
	return s <= p or p <= e;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	LD h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;
	if (h >= 12)
		h -= 12;
	h += m / 60 + s / 3600;
	m = m / 5 + s / 300;
	s = s / 5;
	int cnt = f(t1, t2, h) +
		f(t1, t2, m) +
		f(t1, t2, s);
	if (cnt == 0 or cnt == 3)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}