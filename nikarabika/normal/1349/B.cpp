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
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
        return cout << (a[0] == k ? "yes\n" : "no\n"), 0;
    bool big = false;
    for (int i = 0; i + 2 < n; i++) {
        int b[3] = {a[i], a[i + 1], a[i + 2]};
        sort(b, b + 3);
        if (b[1] == k)
            return cout << "yes\n", 0;
        if (b[1] > k)
            big = true;
    }
    for (int i = 0; i + 1 < n; i++) {
        int b[2] = {a[i], a[i + 1]};
        sort(b, b + 2);
        if (b[0] == k)
            return cout << "yes\n", 0;
        if (b[0] > k)
            big = true;
    }
    bool eq = count(a, a + n, k);
    if (eq and big)
        return cout << "yes\n", 0;
    cout << "no\n";
    return 0;
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