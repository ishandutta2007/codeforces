#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        ll x;
        cin >> x;
        string s;
        cin >> s;
        vector<ll> v;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {c += k;}
            else {
                if (c != 0) v.push_back(c);
                v.push_back(-1);
                c = 0;
            }
        }
        if (c != 0) v.push_back(c);
        string u;
        x--;
        for (int i = v.size()-1; i >= 0; i--) {
            if (v[i] == -1) u += 'a';
            else {
                for (int j = 0; j < x%(v[i]+1); j++) u += 'b';
                x /= (v[i]+1);
            }
        }
        reverse(u.begin(),u.end());
        cout << u << "\n";
   }
}