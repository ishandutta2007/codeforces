#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
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
    return pi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = (int) s.length();
        int ind = 0;
        while (ind < n / 2 && s[ind] == s[n - ind - 1])
            ind++;
        string ans = "";
        if (ind)
        {
            ans += s.substr(0, ind);
        }
        if (ind < (n + 1) / 2)
        {
            int len = 2 * (n / 2 - ind) + (n % 2 != 0);
            string ss = s.substr(ind, len);
            reverse(ss.begin(), ss.end());
            ss = s.substr(ind, len) + "#" + ss;
            vector<int> v = prefix_function(ss);
            int best = v[(int) v.size() - 1];
            ss = s.substr(ind, len);
            reverse(ss.begin(), ss.end());
            ss = ss + "#" + s.substr(ind, len);
            v = prefix_function(ss);
            if (v[(int) v.size() - 1] > best)
            {
                ans += s.substr(n - ind - v[(int) v.size() - 1], v[(int) v.size() - 1]);
            }
            else
            {
                ans += s.substr(ind, best);
            }
        }
        if (ind)
        {
            ans += s.substr(n - ind, ind);
        }
        cout << ans << "\n";
    }
    return 0;
}