#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll laske(ll x) {
    ll c = 0;
    for (ll u = 5; u <= x; u *= 5) {
        c += x/u;
    }
    return c;
}

int m;

vector<int> v;

int main() {
    cin >> m;
    for (int i = 1; ; i++) {
        int u = laske(i);
        if (u == m) v.push_back(i);
        if (u > m) break;
    }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";
}