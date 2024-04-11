#include <bits/stdc++.h>

using namespace std;
const int c=52, k=20005;
int s, m, p, n, t[c][k], pref[c][k], dp[c][k], emax[c][k], hmax[c][k], pre[c][k], suf[c][k], maxi;
int calc(int sor, int kezd, int veg) {
    return pref[sor][veg]-pref[sor][kezd-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s >> n >> m;
    p=n-m+1;
    for (int i=1; i<=s; i++) {
        for (int j=1; j<=n; j++) {
            cin >> t[i][j];
            pref[i][j]=pref[i][j-1]+t[i][j];
        }
    }
    for (int sor=2; sor<=s+1; sor++) {
        for (int pos=1; pos<=p; pos++) {
            dp[sor][pos]=calc(sor-1, pos, pos+m-1)+max(emax[sor-1][max(0, pos-m)], hmax[sor-1][pos+m]);
        }
        deque<int> q;
        for (int pos=1; pos<=p; pos++) {
            while (q.size()>0 && suf[sor-1][pos]>suf[sor-1][q.back()]) {
                q.pop_back();
            }
            q.push_back(pos);
            if (pos-q.front()>=m) {
                q.pop_front();
            }
            dp[sor][pos]=max(dp[sor][pos], suf[sor-1][q.front()]-calc(sor-1, pos+m, n));

        }
        q.clear();

        for (int pos=p; pos>=1; pos--) {
            while (q.size()>0 && pre[sor-1][pos]>pre[sor-1][q.back()]) {
                q.pop_back();
            }
            q.push_back(pos);
            if (q.front()-pos>=m) {
                q.pop_front();
            }
            dp[sor][pos]=max(dp[sor][pos], pre[sor-1][q.front()]-calc(sor-1, 1, pos-1));
        }


        for (int pos=1; pos<=p; pos++) {
            dp[sor][pos]+=calc(sor, pos, pos+m-1);
            emax[sor][pos]=max(emax[sor][pos-1], dp[sor][pos]);
            pre[sor][pos]=dp[sor][pos]+calc(sor, 1, pos-1);
            suf[sor][pos]=dp[sor][pos]+calc(sor, pos+m, n);
            maxi=max(maxi, dp[sor][pos]);
        }
        for (int pos=p; pos>=1; pos--) {
            hmax[sor][pos]=max(hmax[sor][pos+1], dp[sor][pos]);
        }
    }
    cout << maxi << "\n";
    return 0;
}