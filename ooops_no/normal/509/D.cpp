#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

int L = 1, R = 1e10;

void merge(int l, int r){
    pair<int,int> p{max(l, L), min(r, R)};
    L = p.first, R = p.second;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> w(n, vector<int>(m));
    vector<set<int>> st_col(m), st_row(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> w[i][j];
            merge(w[i][j] + 1, 1e10);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j + 1 < m; j++){
            st_col[j].insert(w[i][j + 1] - w[i][j]);
        }
    }
    for (int j = 0; j + 1 < m; j++){
        if (st_col[j].size() <= 1) continue;
        if (st_col[j].size() > 2){
            cout << "NO\n";
            return 0;
        }
        int a = *st_col[j].begin(), b = *st_col[j].rbegin();
        if (max(a, b) < 0 || min(a, b) > 0){
            cout << "NO\n";
            return 0;
        }
        merge(max(a, b) - min(a, b), max(a, b) - min(a, b));
    }
    for (int i = 0; i + 1 < n; i++){
        for (int j = 0; j < m; j++){
            st_row[i].insert(w[i + 1][j] - w[i][j]);
        }
    }
    for (int i = 0; i + 1 < n; i++){
        if (st_row[i].size() <= 1) continue;
        if (st_row[i].size() > 2){
            cout << "NO\n";
            return 0;
        }
        int a = *st_row[i].begin(), b = *st_row[i].rbegin();
        if (max(a, b) < 0 || min(a, b) > 0){
            cout << "NO\n";
            return 0;
        }
        merge(max(a, b) - min(a, b), max(a, b) - min(a, b));
    }
    if (L <= R){
        int k = L;
        vector<int> b(m), a(n);
        for (int i = 0; i + 1 < m; i++){
            b[i + 1] = (b[i] + *st_col[i].begin() + k) % k;
        }
        for (int i = 0; i < n; i++){
            a[i] = (w[i][0] - b[0] + k) % k;
        }
        cout << "YES\n";
        cout << k << endl;
        for (auto to : a) cout << to << ' ';
        cout << endl;
        for (auto to : b) cout << to << ' ';
        cout << endl;
    }
    else{
        cout << "NO\n";
    }
    return 0;
}