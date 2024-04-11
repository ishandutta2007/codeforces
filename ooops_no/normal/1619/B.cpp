#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a;
    for (int i = 1; i * i <= 1e9; i++){
        a.pb(i * i);
    }
    for (int i = 1; i * i * i <= 1e9; i++){
        a.pb(i * i * i);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << upper_bound(a.begin(), a.end(), n) - a.begin() << endl;
    }
    return 0;
}