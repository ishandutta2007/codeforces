#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> v;

void haku(ll x, int c) {
    if (x > 1000000000000000000) return;
    if (c == 1) v.push_back(x);
    haku(x*2+1,c);
    if (c == 0) haku(x*2+0,1);
}

int main() {
    haku(1,0);
    ll a, b;
    cin >> a >> b;
    int c = 0;
    for (int i = 0; i < v.size(); i++) {
        if (a <= v[i] && v[i] <= b) c++;
    }
    cout << c << "\n";
}