#include <bits/stdc++.h>

using namespace std;
const int c=500005, sok=1e9;
int w, n, m, kis, nagy, pos, cnt;
vector<pair<int, int> > bal, jobb;
vector<int> t[c], sz[c];
bool v[c];
void dfs(int a) {
    //cout << "dfs " << a << "\n";
    v[a]=true;
    cnt++;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            t[i].resize(m+1);
            for (int j=1; j<=m; j++) {
                cin >> t[i][j];
            }
        }
        kis=nagy=1;
        for (int i=1; i<=n; i++) {
            if (t[i][1]<t[kis][1]) kis=i;
            if (t[i][1]>t[nagy][1]) nagy=i;
        }
        for (int i=1; i<=m; i++) if (t[kis][i]<t[nagy][i]) pos=i;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
            if (j<=pos) bal.push_back({-t[i][j], i});
            else jobb.push_back({t[i][j], i});
        }
        sort(bal.begin(), bal.end()), sort(jobb.begin(), jobb.end());
        int sb=bal.size(), sj=jobb.size();
        for (int i=0; i<sb-1; i++) {
            int a=bal[i].second, b=bal[i+1].second;
            sz[a].push_back(b);
            if (bal[i].first==bal[i+1].first) sz[b].push_back(a);
        }
        for (int i=0; i<sj-1; i++) {
            int a=jobb[i].second, b=jobb[i+1].second;
            sz[a].push_back(b);
            if (jobb[i].first==jobb[i+1].first) sz[b].push_back(a);
        }

        dfs(kis);
        int kbal=0, kjobb=sok, pbal=sok, pjobb=0;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
            if (v[i]) {
                if (j<=pos) kbal=max(kbal, t[i][j]);
                else kjobb=min(kjobb, t[i][j]);
            } else {
                if (j<=pos) pbal=min(pbal, t[i][j]);
                else pjobb=max(pjobb, t[i][j]);
            }
        }
        if (cnt==n || kbal>=pbal || pjobb>=kjobb || pos==0 || pos==m) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i=1; i<=n; i++) cout << (v[i] ? 'B' : 'R');
            cout << " " << pos << "\n";
        }
        for (int i=1; i<=n; i++) {
            t[i].clear();
            sz[i].clear();
            v[i]=0;
        }
        kis=0, nagy=0, pos=0, cnt=0;
        bal.clear(), jobb.clear();
    }
    return 0;
}
/*
1
3 3
8 9 8
1 5 3
7 5 7
*/