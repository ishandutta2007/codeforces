#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    map<char, int> m;
    m['B'] = 0;
    m['S'] = 0;
    m['C'] = 0;

    string burger;
    cin >> burger;

    for (char i : burger) {
        m[i] += 1;
    }

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;

    ll r;
    cin >> r;

    ll lo = 0, hi = 1e15, mid;

    while (lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        if (max(0LL, p1 * (mid * m['B'] - n1)) + max(0LL, p2 * (mid * m['S'] - n2)) + max(0LL, p3 * (mid * m['C'] - n3)) <= r)
            lo = mid;
        else
            hi = mid - 1;
    }

    cout << lo;
    return 0;
}