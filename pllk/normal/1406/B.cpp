#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a, b;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x >= 0) {
                a.push_back(x);
            } else {
                b.push_back(x);
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int an = a.size();
        int bn = b.size();
        vector<ll> v;
        if (an >= 5) {
            ll x = 1;
            for (int i = an-1; i >= an-5; i--) {
                x *= a[i];
            }
            v.push_back(x);
        }
        if (an >= 4 && bn >= 1) {
            ll x = 1;
            for (int i = an-1; i >= an-4; i--) {
                x *= a[i];
            }
            for (int i = bn-1; i >= bn-1; i--) {
                x *= b[i];
            }
            v.push_back(x);
        }
        if (an >= 3 && bn >= 2) {
            ll x = 1;
            for (int i = an-1; i >= an-3; i--) {
                x *= a[i];
            }
            for (int i = 0; i < 2; i++) {
                x *= b[i];
            }
            v.push_back(x);
        }
        if (an >= 2 && bn >= 3) {
            ll x = 1;
            for (int i = an-1; i >= an-2; i--) {
                x *= a[i];
            }
            for (int i = bn-1; i >= bn-3; i--) {
                x *= b[i];
            }
            v.push_back(x);
        }
        if (an >= 1 && bn >= 4) {
            ll x = 1;
            for (int i = an-1; i >= an-1; i--) {
                x *= a[i];
            }
            for (int i = 0; i < 4; i++) {
                x *= b[i];
            }
            v.push_back(x);
        }
        if (bn >= 5) {
            ll x = 1;
            for (int i = bn-1; i >= bn-5; i--) {
                x *= b[i];
            }
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        cout << v.back() << "\n";
    }
}