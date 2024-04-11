#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, cnt;
vector<int> sz[c];
bool v[c];
bool dfs(int a) {
    v[a]=true;
    bool jo=0;
    for (auto x:sz[a]) {
        if (!v[x]) {
            if (dfs(x)) {
                jo=1;
            }
        }
    }
    if (!jo) {
        cnt++;
    }
    return (!jo);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        bool x=dfs(1);

        //cout << "valasz: ";
        cout << 2*cnt+1-n-x << "\n";


        for (int i=1; i<=n; i++) {
            v[i]=0;
            sz[i].clear();
        }
        cnt=0;
    }
    return 0;
}