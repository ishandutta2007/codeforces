#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector<int>> v(n, vector<int>(m));
    vector<int> ans;
    for (int i = 0; i < n; i++){
        ans.push_back(1);
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        int ll = v[0][ans[0] - 1];
        for (int ii = 1; ii < n; ii++){
            ll ^= v[ii][ans[ii] - 1];
        }
        if (ll == 0){
            for (int j = 1; j < m; j++){
                if (v[i][0] != v[i][j]) {ans[i] = j + 1; break;}
            }
        }
    }
    int ll = v[0][ans[0] - 1];
    for (int ii = 1; ii < n; ii++){
        ll ^= v[ii][ans[ii] - 1];
    }
    if (ll == 0){
        cout << "NIE";
        return 0;
    }
    cout << "TAK" << endl;
    for (auto to : ans){
        cout << to << " ";
    }
}