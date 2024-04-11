#include <bits/stdc++.h>

using namespace std;
const int c=1000205, k=26;
int n, q, pi[c], dp[c][k];
string s, t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n=s.size();


    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    dp[0][s[0]-'a']=1;
    for (int i=1; i<n; i++) {
        for (int j=0; j<26; j++) {
            dp[i][j]=(s[i]-'a'==j ? i+1 : dp[pi[i-1]][j]);
        }
    }
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int m=t.size();
        for (int i=n; i<n+m; i++) {
            s.push_back(t[i-n]);
            int j=pi[i-1];
            while (j>n-1 && s[i]!=s[j]) {
                j=pi[j-1];
            }
            if (s[i]==s[j]) {
                j++;
                pi[i]=j;
            } else {
                pi[i]=dp[j][s[i]-'a'];
            }
            cout << pi[i] << " ";
        }
        cout << "\n";
        for (int i=0; i<m; i++) {
            s.pop_back();
        }
    }
    return 0;
}