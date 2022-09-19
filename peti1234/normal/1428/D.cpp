#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, t[c], pos[c], pr, col=1, epos;
vector<pair<int, int>> sol;
void pb(int a, int b) {
    sol.push_back({b, a});
    pos[a]=b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=1; i<=n; i++) {
        if (t[i]==1) {
            if (!pos[i]) {
                pb(i, col);
                col++;
            }
        }
        if (t[i]==2) {
            epos=max(i, epos);
            while(epos<=n && t[epos]!=1) epos++;
            if (epos>n) pr=1;
            else {
                if (!pos[i]) {
                    pb(i, col);
                    col++;
                }
                pb(epos, pos[i]);
            }
            epos++;
        }
        if (t[i]==3) {
            int cel=i+1;
            while((pos[cel] || t[cel]==0) && cel<=n) cel++;
            if (cel>n) pr=1;
            else {
                if (!pos[i]) {
                    pb(i, col);
                    col++;
                }
                pb(cel, pos[i]);
                pb(cel, col);
                col++;
            }
        }
    }
    if (pr) cout << -1 << "\n";
    else {
        cout << sol.size() << "\n";
        for (int i=0; i<sol.size(); i++) {
            cout << sol[i].first << " " << sol[i].second << "\n";
        }
    }
    return 0;
}