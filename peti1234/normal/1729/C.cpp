#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        string s;
        int n;
        cin >> s;
        n=s.size();
        bool spec=0;
        if (s[0]>s[n-1]) {
            spec=1;
            reverse(s.begin(), s.end());
        }
        vector<pair<char, int> > sz;
        for (int i=0; i<n; i++) {
            if (s[0]<=s[i] && s[i]<=s[n-1]) {
                sz.push_back({s[i], i+1});
            }
        }
        sort(sz.begin(), sz.end());
        if (spec) reverse(sz.begin(), sz.end());
        cout << abs(s[n-1]-s[0]) << " " << sz.size() << "\n";
        for (auto x:sz) {
            int ert=x.second;
            if (spec) ert=n+1-ert;
            cout << ert << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
1
logic
*/