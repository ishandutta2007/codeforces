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
    for (int i = 0; i + 1 < n; i++){
        if (s[i] != s[i + 1]){
            cout << i + 1 << ' ' << i + 2 << endl;
            return;
        }
    }
    cout << -1 << ' ' << -1 << endl;
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