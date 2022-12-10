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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mn = *min_element(a, a + n);
    vector<int> vec;
    for (int i = 0; i < n; i++)
        if (a[i] % mn == 0)
            vec.PB(a[i]);
    sort(all(vec));
    int ptr = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % mn == 0)
            a[i] = vec[ptr++];
    for (int i = 0; i + 1 < n; i++)
        if (a[i] > a[i + 1])
            return cout << "NO\n", 0;
    return cout << "YES\n", 0;
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