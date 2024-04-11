#include <bits/stdc++.h>

using namespace std;
int t[100002], n, q;
unordered_map<int, long long> m;
void solve(int a, int b) {
    if (a>b) return;
    int mid=(a+b)/2, lv=t[mid], rv=t[mid];
    vector<pair<int, long long> > l, r;
    l.push_back({t[mid], 1}), r.push_back({t[mid], 1});
    for (int i=mid-1; i>=a; i--) {
        lv=__gcd(lv, t[i]);
        if (lv!=l.back().first) {
            l.push_back({lv, 0});
        }
        l.back().second++;
    }
    for (int i=mid+1; i<=b; i++) {
        rv=__gcd(rv, t[i]);
        if (rv!=r.back().first) {
            r.push_back({rv, 0});
        }
        r.back().second++;
    }
    for (pair<int, long long> i:l) {
        for (pair<int, long long> j:r) {
            int ert=__gcd(i.first, j.first);
            long long db=i.second*j.second;
            m[ert]+=db;
        }
    }
    solve(a, mid-1), solve(mid+1, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    solve(1, n);
    cin >> q;
    for (int i=1; i<=q; i++) {
        int x; cin >> x;
        cout << m[x] << endl;
    }
    return 0;
}