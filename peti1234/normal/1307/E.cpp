#include <bits/stdc++.h>

using namespace std;
const int c=5002;
long long n, m, s[c], dp[c][c], db[c], ert[c], ossz[c], maxi, sum, pr, mod=1e9+7;
bool sp[c];
vector<int> sz[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> s[i], ossz[s[i]]++;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b);
    }
    for (int i=1; i<=n; i++) {
        sort(sz[i].begin(), sz[i].end());
    }
    for (int i=0; i<=n; i++) {
        bool jo=0;
        int cnt=0;
        if (!i) jo=1;
        else db[s[i]]++;
        for (int j=1; j<=n; j++) {
            int bal=0, jobb=0;
            bool kul=0;
            for (int k:sz[j]) {
                if (k<=db[j]) bal++;
                if (k==db[j] && s[i]==j) kul=1;
                else if (k<=ossz[j]-db[j]) jobb++;
            }
            if (kul) {
                jo=1;
                cnt++;
                if (jobb) cnt++, dp[i][j]=jobb;
            } else {
                if (bal>jobb) swap(bal, jobb);
                if (!bal) {
                    if (jobb) {
                        cnt++;
                        dp[i][j]=jobb;
                    }
                } else {
                    if (jobb==1) {
                        cnt++;
                        dp[i][j]=2;
                    } else {
                        cnt+=2;
                        dp[i][j]=bal*(jobb-1);
                    }
                }
            }
        }
        ert[i]=cnt;
        maxi=max(maxi, ert[i]);
        sp[i]=jo;
    }
    for (int i=0; i<=n; i++) {
        if (ert[i]==maxi && sp[i]) {
            pr=1;
            for (int j=1; j<=n; j++) {
                if (dp[i][j]) pr*=dp[i][j], pr%=mod;
            }
            sum+=pr, sum%=mod;
        }
    }
    if (!maxi) sum=1;
    cout << maxi << " " << sum << "\n";
    return 0;
}