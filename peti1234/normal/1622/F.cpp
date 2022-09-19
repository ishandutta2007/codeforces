#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, pr[c];
unsigned long long ert[c], xo;
void co(vector<int> sz) {
    int si=sz.size();
    cout << n-si << "\n";
    for (int i=1; i<=n; i++) {
        bool baj=0;
        for (auto x:sz) if (x==i) baj=1;
        if (!baj) cout << i << " ";
    }
    cout << "\n";
    exit(0);
}
void solve() {
    if (!xo) co({});
    map<unsigned long long, int> m;
    for (int i=1; i<=n; i++) {
        if (xo==ert[i]) co({i});
        m[ert[i]]=i;
    }
    for (auto x:m) {
        unsigned long long p=xo^x.first;
        if (m.find(p)!=m.end()) {
            co({x.second, m[p]});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    for (int i=2; i<=n; i++) {
        if (!pr[i]) {
            ert[i]=rng();
            for (int j=i; j<=n; j+=i) {
                pr[j]=i;
            }
        } else ert[i]=ert[i/pr[i]]^ert[pr[i]];
    }
    for (int i=1; i<=n; i++) {
        ert[i]^=ert[i-1];
        xo^=ert[i];
    }
    solve();
    xo^=ert[n], n--;
    solve();
    return 0;
}