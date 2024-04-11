#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

#define ll long long

int n, k;
unordered_map<ll,int> z;
vector<ll> v;
int q;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        for (int i = 1; i <= k; i++) {
            ll u = a*i;
            if (z[u] == 0 || z[u] > i) z[u] = i;
            v.push_back(u);
        }
    }
    z[0] = 0;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll d;
        cin >> d;
        int t = -1;
        for (int j = 0; j < v.size(); j++) {
            ll x = d;
            ll a = v[j];
            if (a > x) continue;
            if (!z.count(a)) continue;
            int c = 0;
            x -= a;
            c += z[a];
            if (!z.count(x)) continue;
            c += z[x];
            if (c > k) continue;
            if (t == -1 || c < t) t = c;
        }
        cout << t << "\n";
    }
}