#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int n, m, lcp[c][c];
string s;
long long ert, sok=1e18+1, dp[c][c];
vector<pair<int, int> > sub;
bool comp(pair<int, int> a, pair<int, int> b) {
    int afi=a.first, ase=a.second, bfi=b.first, bse=b.second, db=lcp[afi][bfi];
    if (min(ase, bse)<=db) {
        return (ase<=bse);
    }
    return s[afi+db]<=s[bfi+db];
}
void valt(int i, int j) {
    dp[i][j]=min(dp[i][j], sok);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> ert >> s;
    for (int i=n-1; i>=0; i--) {
        for (int j=n-1; j>=0; j--) {
            if (s[i]==s[j]) {
                lcp[i][j]=1+lcp[i+1][j+1];
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=1; i+j<=n; j++) {
            sub.push_back({i, j});
        }
    }
    stable_sort(sub.begin(), sub.end(), comp);
    int lo=0, hi=sub.size(), mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        int fi=sub[mid].first, se=sub[mid].second;
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                dp[i][j]=0;
            }
        }
        dp[0][0]=1;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                dp[i+1][j]+=dp[i][j];
                valt(i+1, j);
                if (comp(sub[mid], {i-1, n-i+1})) {
                    int koz=min(lcp[fi][i-1], se), pos=i+koz;
                    if (koz>=se) {
                        pos--;
                    }
                    dp[pos][j+1]+=dp[i-1][j];
                    valt(pos, j+1);
                }
            }
        }
        long long sum=dp[n][m];
        if (sum>=ert) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    cout << s.substr(sub[lo].first, sub[lo].second);
    return 0;
}