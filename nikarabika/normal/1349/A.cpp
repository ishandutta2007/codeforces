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

const int maxn = 2e5 + 10;
vector<int> vec[maxn];

LL Pow(LL x, LL y) {
    LL ans = 1;
    for (int i = 0; i < y; i++)
        ans *= x;
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int p = 2; p * p <= x; p++)
            if (x % p == 0) {
                int cnt = 0;
                while (x % p == 0)
                    cnt++, x /= p;
                vec[p].PB(cnt);
            }
        if (x > 1)
            vec[x].PB(1);
    }
    LL ans = 1;
    for (int i = 0; i < maxn; i++) {
        sort(all(vec[i]));
        if (sz(vec[i]) <= n - 2)
            continue;
        else if (sz(vec[i]) == n - 1)
            ans *= Pow(i, vec[i][0]);
        else
            ans *= Pow(i, vec[i][1]);
    }
    cout << ans << endl;
	return 0;
}