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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    LL a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1) {
        cout << "1 1\n" << -a[0] << '\n' << "1 1\n0\n1 1\n0\n";
        return 0;
    }
    cout << 1 << ' ' << n - 1 << '\n';
    for (int i = 0; i < n - 1; i++) {
        LL val = 1LL * (n - 1) * (a[i] % n);
        a[i] += val;
        cout << val << ' ';
    }
    cout << '\n';
    cout << n << ' ' << n << '\n';
    cout << -a[n - 1] << '\n';
    a[n - 1] = 0;
    cout << 1 << ' ' << n << '\n';
    for (int i = 0; i < n; i++)
        cout << -a[i] << ' ';
    cout << '\n';
	return 0;
}