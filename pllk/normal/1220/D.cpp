    #include <iostream>
    #include <vector>
     
    using namespace std;
     
    typedef long long ll;
     
    int n;
    ll b[202020];
    int c[100];
     
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            int u = 0;
            for (ll x = 2; x <= 2e18; x *= 2) {
                if (b[i]%x == x/2) c[u]++;
                u++;
            }
        }
        int f = 0;
        int u = 0;
        ll h = 0;
        for (ll x = 2; x <= 2e18; x *= 2) {
            if (c[u] >= c[f]) {f = u; h = x;}
            u++;
        }
        vector<ll> v;
        for (int i = 0; i < n; i++) {
            if (b[i]%h != h/2) v.push_back(b[i]);
        }
        cout << v.size() << "\n";
        for (auto x : v) cout << x << " ";
        cout << "\n";
    }