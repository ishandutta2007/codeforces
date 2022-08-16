#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5;

void sorting(ll &r, ll &g, ll &b) {
    if (r > g) swap(r, g);
    if (g > b) swap(g, b);
    if (r > g) swap(r, g);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll r, g, b;
    cin >> r >> g >> b;

    sorting(r, g, b);

    if (2 * (r + g) <= b) cout << r + g << "\n";
    else cout << (r + g + b) / 3 << "\n";
    return 0;
}