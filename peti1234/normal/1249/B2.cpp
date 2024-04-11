#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, t[c], sol[c], v[c];
vector<int> sz;
void dfs(int a) {
    v[a]=1, sz.push_back(a);
    if (!v[t[a]]) dfs(t[a]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i], v[i]=0;
        }
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                dfs(i);
                int si=sz.size();
                for (int i=0; i<si; i++) {
                    sol[sz[i]]=si;
                }
                sz.clear();
            }
        }
        for (int i=1; i<=n; i++) {
            cout << sol[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}