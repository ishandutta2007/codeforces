#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll s;
ll a[101010];
ll lol;

bool ok(int k) {
    vector<ll> u;
    for (int i = 1; i <= n; i++) {
        u.push_back(a[i]+(ll)i*k);
    }
    sort(u.begin(),u.end());
    ll z = 0;
    for (int i = 0; i < k; i++) z += u[i];
    lol = z;
    return z <= s;
}

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int k = 0;
    for (int b = n; b >= 1; b /= 2) {
        while (k+b <= n && ok(k+b)) k += b;
    }
    ok(k);
    cout << k << " " << lol << "\n";
}