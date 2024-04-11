#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    set<int> st;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    for (int j = 0; j + 1 < m; j++){
        for (int i = 1; i < n; i++){
            if (v[i][j] == 'X' && v[i - 1][j + 1] == 'X'){
                st.insert(j);
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        auto it = st.lower_bound(a);
        if (it == st.end()){
            cout << "YES\n";
        }
        else if (*it < b){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}