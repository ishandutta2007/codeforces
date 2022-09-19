#include <bits/stdc++.h>

using namespace std;
const int c=1002, k=10002, f=k/2;
int w, n, m, dp[c][k], baj, si1, si2;
vector<int> p, jobb, bal, fel, le, s1, s2;
void ks() {
    random_shuffle(p.begin(), p.end());
    int si=p.size();
    for (int i=0; i<=si; i++) {
        for (int j=0; j<k; j++) dp[i][j]=0;
    }
    dp[0][f]=1;
    for (int i=1; i<=si; i++) {
        int x=p[i-1];
        for (int j=0; j<k; j++) {
            if (j>=x && dp[i-1][j-x]) {
                dp[i][j]=1;
            }
            if (k-1-x>=j && dp[i-1][j+x]) {
                dp[i][j]=1;
            }
        }
    }
    int g=f;
    for (int i=si-1; i>=0; i--) {
        int x=p[i];
        if (x<=g && dp[i][g-x]) {
            s1.push_back(x);
            g-=x;
        } else {
            s2.push_back(x);
            g+=x;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> w;
    while(w--) {
        p.clear(), jobb.clear(), bal.clear(), fel.clear(), le.clear(), s1.clear(), s2.clear();
        baj=0;
        cin >> n;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            p.push_back(x);
        }
        ks();
        if (!dp[n][f]) baj=1;
        si1=s1.size(), si2=s2.size();
        if (si1<si2) {
            for (int i=0; i<si1; i++) jobb.push_back(s1[i]);
            for (int j=0; j<si2; j++) bal.push_back(s2[j]);
        }
        else {
            for (int i=0; i<si1; i++) bal.push_back(s1[i]);
            for (int j=0; j<si2; j++) jobb.push_back(s2[j]);
        }
        p.clear();
        s1.clear(), s2.clear();
        cin >> m;
        for (int i=0; i<m; i++) {
            int x; cin >> x;
            p.push_back(x);
        }
        ks();
        if (!dp[m][f]) baj=1;
        si1=s1.size(), si2=s2.size();
        if (si1<si2) {
            for (int i=0; i<si1; i++) le.push_back(s1[i]);
            for (int j=0; j<si2; j++) fel.push_back(s2[j]);
        }
        else {
            for (int i=0; i<si1; i++) fel.push_back(s1[i]);
            for (int j=0; j<si2; j++) le.push_back(s2[j]);
        }
        s1.clear(), s2.clear();
        if (n!=m) baj=1;
        if (baj) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            sort(bal.rbegin(), bal.rend()), sort(jobb.rbegin(), jobb.rend());
            sort(fel.begin(), fel.end()), sort(le.begin(), le.end());
            int x=0, y=0;
            int fs=fel.size(), js=jobb.size();
            for (int i=0; i<n; i++) {
                if (i<js) x+=jobb[i];
                else x-=bal[i-js];
                cout << x << " " << y << "\n";
                if (i<fs) y+=fel[i];
                else y-=le[i-fs];
                cout << x << " " << y << "\n";
            }
        }
    }
    return 0;
}