#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
ll a, b;
vector<ll> v;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        while (true) {
            int n = v.size();
            if (n < 3) break;
            ll a = v[n-3];
            ll b = v[n-2];
            ll c = v[n-1];
            if ((a >= 0 && b >= 0 && c <= 0) || (a <= 0 && b <= 0 && c >= 0)) {
                v.pop_back();
                v.pop_back();
                v.push_back(c-b);
            } else if ((a >= 0 && b <= 0 && c >= 0) || (a <= 0 && b >= 0 && c <= 0)) {
                v.pop_back();
                v.pop_back();
                v.push_back(b-c);
            } else if ((a <= 0 && b >= 0 && c >= 0) || (a >= 0 && b <= 0 && c <= 0)) {
                v.pop_back();
                v.pop_back();
                v.pop_back();
                v.push_back(a-b);
                v.push_back(c);
            } else break;
        }
    }
    if (v.size() == 1) {
        cout << v[0] << "\n";
    } else if (v.size() == 2) {
        cout << max(v[0]-v[1],v[1]-v[0]) << "\n";
    } else {
        ll s = 0;
        ll p = abs(v[0]);
        for (auto x : v) {
            s += abs(x);
            p = min(p,abs(x));
        }
        cout << s-2*p << "\n";
    }
}