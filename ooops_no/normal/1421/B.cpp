#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define int long long

const int N = 210;
int v[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                char c;
                cin >> c;
                if ((i == 0 && j == 0) || (i == n - 1 && j == n - 1)){
                    continue;
                }
                v[i][j] = c - '0';
            }
        }
        vector<pair<int,int>> ans;
        if (v[0][1] == v[1][0]){
            if (v[n - 1][n - 2] == v[0][1]){
                ans.pb({n - 1, n - 2});
            }
            if (v[n - 2][n - 1] == v[0][1]){
                ans.pb({n - 2, n - 1});
            }
        }
        else{
            if (v[n - 1][n - 2] == v[n - 2][n - 1]){
                if (v[0][1] == v[n - 1][n - 2]){
                    ans.pb({0, 1});
                }
                else{
                    ans.pb({1, 0});
                }
            }
            else{
            if (v[0][1] == 0){
                ans.pb({0, 1});
            }
            else{
                ans.pb({1, 0});
            }
            if (v[n - 1][n - 2] == 1){
                ans.pb({n - 1, n - 2});
            }
            else{
                ans.pb({n - 2, n - 1});
            }
            }
        }
        cout << ans.size() << endl;
        for (auto to : ans){
            cout << to.first + 1 << " " << to.second + 1 << endl;
        }
    }
    return 0;
}