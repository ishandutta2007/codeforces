#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define PB push_back
#define MP make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
	ios_base::sync_with_stdio(false);
	ll r, x1, y1, x2, y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	d /= 2.0 * r;
	if((double)d == (int)d)
		cout << (int)d << endl;
	else
		cout << (int)d + 1 << endl;
	return 0;
}