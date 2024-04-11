#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define M 998244353

typedef long long ll;

int n, k;
vector<pair<int,int>> e;

ll pot(int a, int b) {
    if (b == 0) return 1;
    ll u = pot(a,b/2);
    u = u*u%M;
    if (b%2 == 1) u = u*a%M;
    return u;
}

ll inv(int x) {
    return pot(x,M-2);
}

ll ff[333333];

ll ncr(int a, int b) {
    ll r = ff[a];
    r = r*inv(ff[b])%M;
    r = r*inv(ff[a-b])%M;
    return r;
}

int main() {
    ff[0] = 1;
    for (int i = 1; i <= 300000; i++) ff[i] = ff[i-1]*i%M;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        e.push_back({l,1});
        e.push_back({r,2});
    }
    sort(e.begin(),e.end());
    ll u = 0;
    int c = 0;
    for (auto x : e) {
        if (x.second == 1) {
            c++;
            if (c >= k) {
                u += ncr(c-1,k-1);
                u %= M;
            }
        } else {
            c--;
        }
    }
    cout << u << "\n";
}