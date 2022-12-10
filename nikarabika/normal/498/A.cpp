#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
	ios_base::sync_with_stdio(false);
	double x1, y1;
	double x2, y2;
	int n, ans = 0;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	double a1 = y1 - y2, b1 = x2 - x1, c1 = (a1 * x1 + b1 * y1) * (-1);
	cin >> n;
	rep(i, n){
		double a2, b2, c2;
		cin >> a2 >> b2 >> c2;
		if(a1 == 0){
			if(a2 == 0)
				continue;
			double y = (double)(-1) * c1 / b1;
			double x = (-1) * (c2 + y * b2) / a2;
			if((x > x1 and x < x2) or (x < x1 and x > x2))
				ans ++;
			continue;
		}
		double y = (double)(c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);
		double x = (double)(c1 + (double)b1 * y) * (-1) / a1;
		//cerr << x << ' ' << y << endl;
		if(x > x1 && x < x2)
			ans ++;
		else if(x < x1 && x > x2)
			ans ++;
		else if(y < y1 && y > y2)
			ans ++;
		else if(y > y1 && y < y2)
			ans ++;
	}
	cout << ans << endl;
	return 0;
}