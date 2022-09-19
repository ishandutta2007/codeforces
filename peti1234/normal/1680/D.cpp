#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, k, t[c], cnt, sum, ans;
vector<int> sz;
void solve(int pos) {
    long long mini=0, maxi=0, ert=0;
    for (int i=1; i<=n; i++) {
        ert+=t[i];
        if (!t[i]) {
            ert+=sz[pos++];
            pos%=cnt;
        }
        mini=min(mini, ert);
        maxi=max(maxi, ert);
    }
    ans=max(ans, maxi-mini+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sum+=t[i];
        if (!t[i]) cnt++;
    }
    while (cnt) {
        if (cnt*k>=sum+2*k) {
            sz.push_back(k);
            sum+=k;
        } else {
            sz.push_back(cnt*k-sum-k);
            sum+=sz.back();
            if (sz.back()<-k) {
                cout << -1 << "\n";
                return 0;
            }
        }
        cnt--;
    }
    if (sum) {
        cout << -1 << "\n";
        return 0;
    }
    cnt=sz.size();
    solve(0);
    sort(sz.begin(), sz.end());
    for (int i=0; i<cnt; i++) {
        solve(i);
    }
    reverse(sz.begin(), sz.end());
    for (int i=0; i<cnt; i++) {
        solve(i);
    }
    cout << ans << "\n";
    return 0;
}