#include <bits/stdc++.h>

using namespace std;
const int c=70002;
int n, k, t[c], ans[c], kov[c], elso[c], pos;
bitset<c> dp, ujdp, kul;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        ans[i]=t[i];
        if (t[i]>t[pos]) {
            pos=i;
        }
    }
    for (int i=1; i<=k; i++) {
        elso[i]=c;
    }
    k-=t[pos];
    dp[0]=1;
    for (int i=1; i<=n; i++) {
        if (i==pos) {
            continue;
        }
        ujdp=dp|(dp<<t[i]), kul=ujdp^dp;
        for (int j=kul._Find_first(); j<kul.size(); j=kul._Find_next(j)) {
            elso[j]=i;
        }
        dp=ujdp;
    }
    if (k<0 || !dp[k]) {
        cout << -1 << "\n";
        return 0;
    }
    sz.push_back({t[pos], pos});
    for (int i=n; i>=1; i--) {
        if (i==pos) {
            continue;
        }
        if (k>=t[i] && elso[k-t[i]]<i) {
            k-=t[i];
        } else {
            sz.push_back({t[i], i});
        }
    }
    sort(sz.rbegin(), sz.rend());
    int si=sz.size();
    for (int i=0; i<si-1; i++) {
        int se=sz[i].second;
        ans[se]=sz[i].first-sz[i+1].first;
        kov[se]=sz[i+1].second;
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
        if (!kov[i]) {
            cout << 0 << "\n";
        } else {
            cout << 1 << " " << kov[i] << "\n";
        }
    }
    return 0;
}