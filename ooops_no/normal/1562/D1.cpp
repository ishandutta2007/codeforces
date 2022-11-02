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
    int n, q;
    cin >> n >> q;
    vector<int> v(n), pr(n), pr_rev(n);
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        v[i] = (c == '+' ? 1 : -1) * (i % 2 == 0 ? 1 : -1);
        pr[i] = v[i] + (i > 0 ? pr[i - 1] : 0);
        pr_rev[i] = -v[i] + (i > 0 ? pr_rev[i - 1] : 0);
    }
    map<int, set<int>> mp, mp_rev;
    for (int i = 0; i < n; i++){
        mp[pr_rev[i] - (i > 0 ? pr[i - 1] : 0)].insert(i);
        mp_rev[pr[i] - (i > 0 ? pr_rev[i - 1] : 0)].insert(i);
    }
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l % 2 == 0){
            int sum = pr[r] - (l > 0 ? pr[l - 1] : 0);
            if (sum == 0){
                cout << 0 << endl;
                continue;
            }
            int ok = 0;
            auto it = mp[sum - pr[r] + pr_rev[r]].lower_bound(l);
            if (it != mp[sum - pr[r] + pr_rev[r]].end()){
                if (*it <= r){
                    ok = 1;
                }
            }
            cout << 2 - ok << endl;
        }
        else{
            int sum = pr_rev[r] - (l > 0 ? pr_rev[l - 1] : 0);
            if (sum == 0){
                cout << 0 << endl;
                continue;
            }
            int ok = 0;
            auto it = mp_rev[sum - pr_rev[r] + pr[r]].lower_bound(l);
            if (it != mp_rev[sum - pr_rev[r] + pr[r]].end()){
                if (*it <= r){
                    ok = 1;
                }
            }
            cout << 2 - ok << endl;
        }
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