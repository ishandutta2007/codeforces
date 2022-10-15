#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll w, h;
        cin >> w >> h;
        vector<ll> v[4];
        for (int i = 0; i < 4; i++) {
            int k;
            cin >> k;
            v[i].resize(k);
            for (int j = 0; j < k; j++) cin >> v[i][j];
        }
        ll a = (v[0].back()-v[0][0])*h;
        ll b = (v[1].back()-v[1][0])*h;
        ll c = (v[2].back()-v[2][0])*w;
        ll d = (v[3].back()-v[3][0])*w;
        ll m = max(max(a,b),max(c,d));
        cout << m << "\n";
    }
}