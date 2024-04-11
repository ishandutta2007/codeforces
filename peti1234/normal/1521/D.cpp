#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, db[c];
vector<int> sz[c];
bool v[c];
vector<pair<int, int> > el, lanc;
int dfs(int a) {
    v[a]=true;
    bool spec=0;
    int ut=0;
    for (int x:sz[a]) {
        if (!v[x]) {
            int s=dfs(x);
            if (!s || spec) {
                if (s) {
                    lanc.push_back({s, x});
                }
                el.push_back({a, x});
                db[a]--, db[x]--;
            } else {
                if (ut) {
                    lanc.push_back({s, ut});
                    ut=0, spec=1;
                } else {
                    ut=s;
                }
            }
        }
    }
    if (!spec && !ut) {
        ut=a;
    }
    return ut;
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
            db[a]++, db[b]++;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        int s=dfs(1);
        if (s) {
            lanc.push_back({s, 1});
        }
        cout << el.size() << "\n";
        for (int i=0; i<el.size(); i++) {
            cout << el[i].first << " " << el[i].second << " " << lanc[i].second << " " << lanc[i+1].first << "\n";
        }
        for (int i=1; i<=n; i++) {
            sz[i].clear();
            v[i]=0;
        }
        lanc.clear(), el.clear();
    }
    return 0;
}