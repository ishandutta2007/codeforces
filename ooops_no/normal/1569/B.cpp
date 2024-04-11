#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> res(n, vector<int>(n));
    vector<int> a;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '2'){
            a.pb(i);
        }
    }
    if (a.size() == 1 || a.size() == 2){
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < a.size(); i++){
        res[a[i]][a[(i + 1) % a.size()]] = 1;
        res[a[(i + 1) % a.size()]][a[i]] = 2;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) cout << 'X';
            else if (res[i][j] == 0) cout << '=';
            else if (res[i][j] == 1) cout << '+';
            else cout << '-';
        }
        cout << endl;
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}