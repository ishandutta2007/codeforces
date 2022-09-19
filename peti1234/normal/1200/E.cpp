#include <bits/stdc++.h>

using namespace std;
int prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi.back();
}
int n;
string ans, s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> ans;
    for (int i=1; i<n; i++) {
        cin >> s;
        string f=s+"#";
        int a=s.size(), b=ans.size();
        for (int j=max(0, b-a); j<b; j++) {
            f+=ans[j];
        }
        int ert=prefix_function(f);
        ans+=s.substr(ert, a-ert);
    }
    cout << ans << "\n";
    return 0;
}