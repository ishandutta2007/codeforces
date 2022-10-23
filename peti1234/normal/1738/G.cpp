#include <bits/stdc++.h>

using namespace std;


const int c=1005;
bool t[c][c], v[c][c];
int n, k, dp[c][c], pos[c];
vector<pair<int, int> > sz[c];
void cl() {
    for (int i=0; i<=n+1; i++) {
        for (int j=0; j<=n+1; j++) {
            t[i][j]=0, v[i][j]=0, dp[i][j]=0;
        }
        pos[i]=0, sz[i].clear();
    }
}
void solve() {
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=n; j++) {
            t[i][j]=(s[j-1]=='0');
        }
    }
    bool baj=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            if (t[i][j]) {
                dp[i][j]=dp[i-1][j-1]+1;
                sz[dp[i][j]].push_back({i, j});
                if (dp[i][j]>=k) baj=1;
            }
        }
    }
    if (baj) {
        cout << "NO\n";
        cl();
        return;
    }
    for (int i=k-1; i>=1; i--) {
        for (int j=1; j<=n; j++) {
            pos[j]=n+1;
        }
        for (auto x:sz[i]) {
            int a=x.first, b=x.second;
            pos[b]=min(pos[b], a);
        }

        int sor=n-(k-1)+i, oszlop=i, lep=2*(n-k+1);
        //cout << "fontos " << sor << " " << oszlop << " " << lep << "\n";
        for (int i=1; i<=lep; i++) {
            if (oszlop==n || v[sor][oszlop+1] || pos[oszlop]<sor) {
                sor--;
            } else {
                oszlop++;
            }
            //cout << "lep " << sor << " " << oszlop << "\n";
            v[sor][oszlop]=1;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (abs(i-j)>n-k) {
                v[i][j]=1;
            }
        }
    }
    cout << "YES\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
    cl();
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
4 3
1110
0101
1010
0111
*/