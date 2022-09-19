#include <bits/stdc++.h>

using namespace std;
const int c=10000005;
int n, a[c], dp[c], st[c][2], aa[c], ab[c], ba[c], bb[c], cnt;
int lep(int pos, int s) {
    if (!st[pos][s]) {
        st[pos][s]=++cnt;
    }
    return st[pos][s];
}
void solve() {
    cin >> n;
    int ans=0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        int maxi=0;

        int ert=(i^a[i]);
        int pos=0;
        /*if (i==1) {
            cout << "alap " << i << " "<< maxi << "\n";
            cout << "... " << aa[0] << " " << ab[0] << " " << ba[0] << " " << bb[0] << "\n";
        }*/
        for (int j=29; j>=0; j--) {
            if (ert & (1<<j)) {
                if (a[i] & (1<<j)) {
                    maxi=max(maxi, bb[pos]);
                } else {
                    maxi=max(maxi, aa[pos]);
                }
                pos=lep(pos, 1);
            } else {
                if (a[i] & (1<<j)) {
                    maxi=max(maxi, ab[pos]);
                } else {
                    maxi=max(maxi, ba[pos]);
                }
                pos=lep(pos, 0);
            }
            //if (i==1) cout << "ert " << j << " " << pos << " " << maxi << "\n";
        }
        if (i==1) {
            //cout << "fontos " << i << " " << maxi << "\n";
        }
        dp[i]=maxi+1;
        ans=max(ans, dp[i]);

        pos=0;
        for (int j=29; j>=0; j--) {
            if (a[i] & (1<<j)) {
                if (i & (1<<j)) aa[pos]=max(aa[pos], dp[i]);
                else ab[pos]=max(ab[pos], dp[i]);
            } else {
                if (i & (1<<j)) ba[pos]=max(ba[pos], dp[i]);
                else bb[pos]=max(bb[pos], dp[i]);
            }
            if (ert & (1<<j)) {
                pos=lep(pos, 1);
            } else {
                pos=lep(pos, 0);
            }
        }
    }
    cout << ans << "\n";

    for (int i=0; i<=cnt; i++) {
        st[i][0]=0, st[i][1]=0, aa[i]=0, bb[i]=0, ab[i]=0, ba[i]=0, dp[i]=0, a[i]=0;
    }
    cnt=0, ans=0;
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
10
3 8 8 2 9 1 6 2 8 3
*/