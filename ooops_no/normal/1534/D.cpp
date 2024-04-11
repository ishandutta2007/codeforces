#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
#define pb push_back
#define ld long double

const int MOD = 1e9 + 7;

set<pair<int,int>> ans;
int n;

void ask(int r){
    cout << "? " << r << endl;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> d[i];
        if (d[i] == 1){
            ans.insert({min(i, r), max(i, r)});
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << "? " << 1 << endl;
    vector<int> d(n + 1);
    vector<vector<int>> col(2);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        if (d[i] == 1){
            ans.insert({min(i, 1ll), max(i, 1ll)});
        }
        if (d[i] != 0){
            col[d[i] % 2].pb(i);
        }
    }
    if (col[0].size() < col[1].size()){
        for (auto to : col[0]){
            ask(to);
        }
    }
    else{
        for (auto to : col[1]){
            ask(to);
        }
    }
    cout << "!" << endl;
    for (auto to : ans){
        cout << to.first << " " << to.second << endl;
    }
    return 0;
}