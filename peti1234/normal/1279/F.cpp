#include <bits/stdc++.h>

using namespace std;

const int c=1000002;
int n, k, l, ans;
pair<int, int> dp[c];
bool v[c];
string s;
void ch(int ert) {
    for (int i=1; i<=n; i++) {
        int el=max(0, i-l);
        pair<int, int> k1={dp[i-1].first+v[i], dp[i-1].second}, k2={dp[el].first+ert, dp[el].second-1};
        dp[i]=min(k1, k2);
    }
    dp[n].second*=-1;
    //cout << "calc " << ert << " " << dp[n].first << " " << dp[n].second << "\n";
}
int solve() {
    int lo=0, hi=c, mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        ch(mid);
        if (dp[n].second>=k) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    ch(lo);
    if (dp[n].second<k) {
        return 0;
    }
    ch(lo+1);
    return dp[n].first-dp[n].second*(lo+1)-(lo)*(k-dp[n].second);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> l >> s;
    for (int i=0; i<n; i++) {
        v[i+1]=islower(s[i]);
    }
    ans=solve();
    //cout << "reszeredmeny " << ans << "\n";
    //return 0;
    for (int i=1; i<=n; i++) {
        v[i]=!v[i];
    }
    cout << min(ans, solve()) << "\n";
	return 0;
}
/*
4 1 1
AAaa
*/