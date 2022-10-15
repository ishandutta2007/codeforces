#include <iostream>
#include <map>

using namespace std;

#define M 1000000007

typedef long long ll;

ll what(int x) {
    map<int,int> g;
    for (int i = 2; i <= x; i++) {
        int u = i;
        for (int j = 2; j*j <= u; j++) {
            int c = 0;
            while (u%j == 0) {
                c++;
                u /= j;
            }
            if (c) g[j] = max(g[j],c);
        }
        if (u != 1) g[u] = max(g[u],1);
    }
    ll r = 1;
    for (auto w : g) {
        for (int i = 0; i < w.second; i++) {
            r *= w.first;
        }
    }
    return r;
}

int main() {
    ll w[41];
    for (int i = 1; i <= 40; i++) {
        w[i] = what(i);
    }
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll r = n;
        for (int i = 1; i <= 40; i++) {
            r += n/w[i];
            r %= M;
        }
        cout << r << "\n";
    }
}