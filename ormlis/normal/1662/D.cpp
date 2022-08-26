//#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SZ = 3e5 + 1000;



signed main()
{
    fastInp;

    ll t;
    cin >> t;

    while (t--) {
        string u, v;
        cin >> u >> v;

        map<char, ll> cnt1, cnt2;

        for (auto c : u) cnt1[c]++;
        for (auto c : v) cnt2[c]++;

        bool f = 1;
        for (char a = 'A'; a <= 'C'; a++) {
            if (cnt1[a] % 2 != cnt2[a] % 2) {
                f = 0;
            }
        }

        bool f2 = 1;

        string nw1, nw2;
        for (int i = 0; i < u.size(); i++) {
            if (u[i] != 'B') nw1.push_back(u[i]);
            while (nw1.size() >= 2 && nw1.back() == nw1[nw1.size() - 2]) {
                nw1.pop_back();
                nw1.pop_back();
            }
        }

        for (int i = 0; i < v.size(); i++) {
            if (v[i] != 'B') nw2.push_back(v[i]);
            while (nw2.size() >= 2 && nw2.back() == nw2[nw2.size() - 2]) {
                nw2.pop_back();
                nw2.pop_back();
            }
        }


        if (nw1 != nw2) f2 = 0;

        if (f && f2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}