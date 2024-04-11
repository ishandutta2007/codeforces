#include <bits/stdc++.h>

using namespace std;
void solve() {
    string s;
    int p, n, sum=0;
    vector<int> sz[27];
    cin >> s >> p;
    n=s.size();
    for (int i=0; i<n; i++) {
        int ert=s[i]-'a'+1;
        sz[ert].push_back(i);
    }
    vector<int> ans;
    for (int i=1; i<=26; i++) {
        for (auto x:sz[i]) {
            if (sum+i<=p) {
                sum+=i;
                ans.push_back(x);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto x:ans) {
        cout << s[x];
    }
    cout << "\n";
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
stringology
*/