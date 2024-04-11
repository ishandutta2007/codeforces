#include <bits/stdc++.h>

using namespace std;
int w, n, x, mini;
bool v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        vector<int> ans;
        bool baj=0;
        mini=1;
        for (int i=1; i<=n; i++) {
            v[i]=0;
        }
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x<i) {
                baj=1;
            }
            if (!v[x]) {
                ans.push_back(x);
                v[x]=1;
            } else {
                while (v[mini]) {
                    mini++;
                }
                ans.push_back(mini);
                v[mini]=1;
            }
        }
        if (baj) {
            cout << -1 << "\n";
        } else {
            for (auto x:ans) {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}