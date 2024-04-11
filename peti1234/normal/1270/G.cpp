#include <bits/stdc++.h>

using namespace std;
const int c=1e6+2;
int w, n, kov[c];
bool v[c];
vector<int> sol;
void dfs(int a) {
    if (v[a]) {
        int x=a;
        do {
            sol.push_back(x);
            x=kov[x];
        } while (x!=a);
        return;
    }
    v[a]=true;
    dfs(kov[a]);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> w;
    while(w--) {
        cin >> n;
        sol.clear();
        for (int i=1; i<=n; i++) {
            int x, ert; cin >> x;
            ert=i-x;
            v[i]=0;
            kov[i]=ert;
        }
        dfs(1);
        cout << sol.size() << "\n";
        for (int i:sol) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}