#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
pair<ll,ll> p[101010];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        p[i] = {b,a};
    }
    sort(p,p+n);
    ll t = 0;
    int i = 0;
    int j = n-1;
    ll r = 0;
    while (i <= j) {
        if (p[i].first <= t) {
            t += p[i].second;
            r += p[i].second;
            p[i].second = 0;
            i++;
        } else {
            ll a = min(p[i].first-t,p[j].second);
            t += a;
            r += 2*a;
            p[j].second -= a;
            if (p[j].second == 0) j--;
        }
    }
    cout << r << "\n";
}