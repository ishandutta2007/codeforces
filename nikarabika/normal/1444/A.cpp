//sobskdrbhvk
//remember...
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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve() {
    LL p, q;
    cin >> p >> q;
    if (p % q)
        cout << p << '\n';
    else {
        vector<pii> vec;
        int tmp = q;
        for (int i = 2; i * i <= tmp; i++)  {
            if (tmp % i == 0) {
                int num = 1;
                while (tmp % i == 0)
                    num *= i, tmp /= i;
                vec.PB(MP(i, num));
            }
        }
        if (tmp > 1)
            vec.PB(MP(tmp, tmp));
        LL ans = 1;
        for (auto pc: vec) {
            LL tmp = p;
            while (tmp % pc.L == 0)
                tmp /= pc.L;
            smax(ans, tmp * pc.R / pc.L);
        }
        cout << ans << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}