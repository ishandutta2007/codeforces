#include <bits/stdc++.h>

using namespace std;

#define int long long

#define pb push_back

#define mp make_pair

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int v[n][m], v1[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v1[i][j];
        }
    }
    vector<int> ii(n), jj(m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (v[i][j] != v1[i][j]){
            ii[i]++; jj[j]++;
            }
        }
    }
    for (auto to : ii) if (to % 2 != 0){cout << "No"; return 0;};
    for (auto to : jj) if (to % 2 != 0){cout << "No"; return 0;};
    cout << "Yes";
}