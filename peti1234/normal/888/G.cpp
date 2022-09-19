#include <bits/stdc++.h>

using namespace std;
long long ans;
set<int> s;
void solve(vector<int> sz, int b) {
    if (sz.size()<=1 || b==-1) return;
    int val=(1<<b), si=sz.size();
    if ((sz[si-1] & val)==0 || (sz[0] & val)) {
        solve(sz, b-1);
        return;
    }
    int mini=1<<30;
    for (auto x:sz) {
        if (x & val) break;
        int ert=0;
        for (int i=30; i>b; i--) {
            if (x & (1<<i)) ert+=(1<<i);
        }
        ert+=val;
        int xo=val;
        for (int i=b-1; i>=0; i--) {
            int add=(1<<i);
            if ((x & add)) {
                int kov=*s.lower_bound(ert+add);
                if (kov<ert+2*add) ert+=add;
                else xo+=add;
            } else {
                int kov=*s.lower_bound(ert);
                if (kov>=ert+add) {
                    ert+=add;
                    xo+=add;
                }
            }
        }
        mini=min(mini, xo);
    }
    vector<int> kis, nagy;
    for (auto x:sz) {
        if (x & val) nagy.push_back(x);
        else kis.push_back(x);
    }
    solve(kis, b-1), solve(nagy, b-1);
    ans+=mini;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<int> sz;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sz.push_back(x);
        s.insert(x);
    }
    s.insert(1<<30);
    sort(sz.begin(), sz.end());
    solve(sz, 29);
    cout << ans << "\n";
    return 0;
}