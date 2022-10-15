#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int b[112233];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        for (int k = 2; k*k <= n; k++) {
            if (n%k == 0) {
                v.push_back(k);
                if (k != n/k) v.push_back(n/k);
            }
        }
        v.push_back(n);
        sort(v.begin(),v.end());
        for (int i = 0; i < v.size(); i++) b[i] = 1;
        vector<int> u;
        u.push_back(v[0]);
        b[0] = 0;
        for (int i = 1; i < v.size(); i++) {
            bool ok = false;
            for (int j = 0; j < v.size(); j++) {
                if (b[j] && gcd(u[u.size()-1],v[j]) > 1) {
                    u.push_back(v[j]);
                    b[j] = 0;
                    ok = true;
                    break;
                }
            }
            if (!ok) cout << "rip\n";
        }
        for (auto x : u) cout << x << " ";
        cout << "\n";
        cout << (gcd(u[0],u[u.size()-1]) == 1) << "\n";
    }
}