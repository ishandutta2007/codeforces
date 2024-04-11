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
    int n, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        if (a.back() < x){
            cout << x - a.back() + max(0ll, y - (sum - a.back())) << endl;
        }
        else{
            int i = lower_bound(a.begin(), a.end(), x) - a.begin();
            int ans = max(0ll, y - (sum - a[i]));
            if (i != 0){
                i--;
                ans = min(ans, (x - a[i]) + max(0ll, y - (sum - a[i])));
            }
            cout << ans << endl;
        }
    }
    return 0;
}