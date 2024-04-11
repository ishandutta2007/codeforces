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
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = r / 2 - 5; i <= r / 2 + 5; i++){
            if (i <= r) ans = max(ans, r % max(l, i));
        }
        cout << ans << endl;
    }
    return 0;
}