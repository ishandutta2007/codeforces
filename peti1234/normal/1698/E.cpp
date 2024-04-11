#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, k, ans, mod=998244353, t[c];
bool v[c];
vector<pair<int, int> > sz;
void solve() {
    cin >> n >> k;
    ans=1;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x==-1) {
            sz.push_back({t[i]-k, -1});
        } else {
            if (t[i]-x>k) {
                ans=0;
            }
            v[x]=1;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            sz.push_back({i, 1});
        }
    }
    int cnt=0;
    sort(sz.rbegin(), sz.rend());
    for (auto p:sz) {
        if (p.second==-1) {
            ans=ans*cnt%mod;
        }
        cnt+=p.second;
    }
    //cout << "valasz.......... ";
    cout << ans << "\n";

    for (int i=1; i<=n; i++) {
        t[i]=0, v[i]=0;
        ans=0;
    }
    sz.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
3 1
2 1 3
3 -1 -1
*/