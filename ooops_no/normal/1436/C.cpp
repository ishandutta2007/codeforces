#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define int long long


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, pos;
    cin >> n >> x >> pos;
    int l = 0, r = n;
    int cnt = x - 1, cnt1 = n - x;
    bool fuck = 0;
    vector<pair<int, int>> add;
    while(l < r){
        int mid = (r + l) / 2;
        if (pos >= mid){
            l = mid + 1;
            if (pos == mid){
                add.pb({1, 1}   );
                continue;
            }
            add.pb({cnt--, 0});
        }
        else{
            r = mid;
            add.pb({cnt1--, 1});
        }
    }
    if (add.size() == 0){
        cout << 0 << endl;
    }
    else{
        int ans = 1;
        for (int i = 0; i < add.size(); i++){
            ans *= add[i].first;
            ans %= (int)1e9 + 7;
        }
        for (int i = n - add.size(); i > 0; i--){
            ans *= i;
            ans %= (int)1e9 + 7;
        }
        cout << max(0ll, ans) << endl;
    }
    return 0;
}