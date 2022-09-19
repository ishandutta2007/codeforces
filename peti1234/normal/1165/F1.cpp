#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, t[c], t2[c], sum, cnt;
vector<pair<int, int> > sz;
bool solve(int ert) {
    for (int i=1; i<=n; i++) {
        t2[i]=t[i];
    }
    int p=2*sum-ert;
    for (auto x:sz) {
        int a=x.first, b=x.second;
        if (a>ert) continue;
        if (p>a) return false;
        p-=t2[b];
        t2[b]=0;
    }
    if (p>0) return false;
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> t[i], sum+=t[i];
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz.push_back({a, b});
    }
    sort(sz.rbegin(), sz.rend());
    int lo=sum-1, hi=2*sum, mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (solve(mid)) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    cout << hi << "\n";
    return 0;
}