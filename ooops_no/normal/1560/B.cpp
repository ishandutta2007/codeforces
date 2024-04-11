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
#define int long long
#define ll long long

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
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        int n = 2 * b - 2 * a;
        if (c > n || abs(a - b) < n / 2 || a > n || b > n){
            cout << -1 << endl;
        }
        else{
            cout << (c + n / 2 - 1) % n + 1 << endl;
        }
    }
    return 0;
}