#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

set<ll> s;

int main() {
    for (ll k = 1; ; k++) {
        if (k*k > 1e9) break;
        s.insert(2*k*k);
        s.insert(4*k*k);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (s.count(n)) cout << "YES\n";
        else cout << "NO\n";
    }
}