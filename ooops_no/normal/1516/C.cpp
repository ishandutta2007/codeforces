#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

bool func(vector<int> a){
    vector<int> dp(2000 * 100 + 1);
    int sum = 0;
    for (auto to : a) sum += to;
    dp[0] = 1;
    for (int i = 0; i < a.size(); i++){
        for (int j = 2000 * 100 - a[i]; j >= 0; j--){
            dp[j + a[i]] |= dp[j];
        }
    }
    if (sum % 2 == 0 && dp[sum / 2]) return 0;
    else return 1;
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if (func(a)){
        cout << 0 << endl;
    }
    else{
        for (int i = 0; i < n; i++){
            vector<int> b;
            for (int j = 0; j < i; j++) b.pb(a[j]);
            for (int j = i + 1; j < n; j++) b.pb(a[j]);
            if (func(b)){
                cout << 1 << endl << i + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}