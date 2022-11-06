#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
    int n; cin >> n;
    string s;
    getline(cin, s);
    getline(cin, s);
    std::vector<int> v;
    int cn = 0;
    int ma = -1;
    for (int i = 0; i < s.size(); ++i) {
        cn++;
        if (s[i] == ' ' || s[i] == '-') {
            v.pb(cn);
            ma = max(cn, ma);
            cn = 0;
        } 
    }
    ma = max(cn, ma);
    v.pb(cn);
    cn = 0;
    int ss = ma;
    int e = s.size();
    while(ss < e) {
        int m = (ss + e) >> 1ll;
        int nn = 0;
        cn = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (cn + v[i] <= m) {
                cn += v[i];
            } else {
                nn++;
                cn = v[i];
            }
        }
        if (cn) nn++;
        if (nn <= n) {
            e = m;
        } else {
            ss = m + 1;
        }
    }
    cout << ss;
}