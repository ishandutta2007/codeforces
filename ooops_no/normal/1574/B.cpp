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
        int a, b, c, m;
        cin >> a >> b >> c >> m;
        int mx = (a - 1) + (b - 1) + (c - 1);
        int mn = max({a, b, c}) - (a + b + c - max({a, b, c})) - 1;
        if (mn <= m && m <= mx){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}