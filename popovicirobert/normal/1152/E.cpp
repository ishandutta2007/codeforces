#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> a(n), b(n);

    for(i = 1; i < n; i++) {
        cin >> a[i];
    }

    for(i = 1; i < n; i++) {
        cin >> b[i];

        if(a[i] > b[i]) {
            cout << -1;
            return 0;
        }

    }

    vector < vector < pair <int, int> > > g(2 * n);
    map <int, int> mp, nrm;
    int id = 0;

    for(i = 1; i < n; i++) {

        if(mp[a[i]] == 0) {
            mp[a[i]] = ++id;
            nrm[id] = a[i];
        }

        if(mp[b[i]] == 0) {
            mp[b[i]] = ++id;
            nrm[id] = b[i];
        }

        g[mp[a[i]]].push_back({mp[b[i]], i});
        g[mp[b[i]]].push_back({mp[a[i]], i});

    }

    vector <int> sol;

    int nod = 1, cnt = 0;
    for(i = 1; i <= id; i++) {
        if(g[i].size() & 1) {
            nod = i;
            cnt++;
        }
    }

    if(cnt > 2) {
        cout << -1;
        return 0;
    }

    vector <bool> vis(n);
    stack <int> stk;
    stk.push(nod);

    while(stk.size()) {
        nod = stk.top();

        while(g[nod].size() && vis[g[nod].back().second]) {
            g[nod].pop_back();
        }

        if(g[nod].empty()) {
            stk.pop();
            sol.push_back(nod);
        }
        else {
            stk.push(g[nod].back().first);
            vis[g[nod].back().second] = 1;
        }

    }

    if(sol.size() != n) {
        cout << -1;
        return 0;
    }

    for(auto it : sol) {
        cout << nrm[it] << " ";
    }

    //cin.close();
    //cout.close();
    return 0;
}