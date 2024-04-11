#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n, mini=0, ert=0; string s;
        cin >> n >> s;
        for (int i=0; i<n; i++) {
            if (s[i]=='(') ert++;
            else ert--, mini=min(mini, ert);
        }
        cout << -mini << "\n";
    }
    return 0;
}