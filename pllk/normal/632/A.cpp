#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, p;
vector<string> v;
ll c;

int main() {
    cin >> n >> p;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll x = 0;
    for (int i = n-1; i >= 0; i--) {
        x *= 2;
        if (v[i] == "halfplus") x++;
        c += x*p/2;
    }
    cout << c << "\n";
}