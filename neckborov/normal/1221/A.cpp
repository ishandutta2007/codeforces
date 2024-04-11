//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;


int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        multiset<int> s;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            s.insert(a);
        }
        bool ok = false;
        while (!s.empty()){
            if (*s.begin() == 2048) {
                ok = true;
            }
            if (s.size() == 1) {
                break;
            }
            auto it1 = s.begin();
            auto it2 = it1++;
            if (*it1 == *it2) {
                s.insert(*it1 + *it2);
                s.erase(it1);
                s.erase(it2);
            } else {
                s.erase(s.begin());
            }
        }
        if (ok) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}