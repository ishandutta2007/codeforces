#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<deque>
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

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
        vector<int> v(n);
        vector<int> a, b;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            if (v[i] < 0){
                a.pb(v[i]);
            }
            else{
                b.pb(v[i]);
            }
        }
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        int ans = -1e18;
        for (int i = 0; i <= 5; i++){
            if (a.size() >= i && b.size() >= 5 - i){
                int now = 1;
                if (i % 2 == 1){
                    reverse(a.begin(), a.end());
                }
                for (int j = 0; j < i; j++){
                    now *= a[j];
                }
                if (i % 2 == 1){
                    reverse(a.begin(), a.end());
                }
                for (int j = 0; j < 5 - i; j++){
                    now *= b[j];
                }
                ans = max(ans, now);
            }
        }
        cout << ans << endl;
    }
    return 0;
}