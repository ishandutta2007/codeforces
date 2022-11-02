#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> a;
        map<int,int> cnt;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            a.pb(v[i]);
            cnt[v[i]]++;
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        for (auto to : a) cout << to << ' ';
        for (auto to : cnt){
            for (int j = 0; j < to.second - 1; j++){
                cout << to.first << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}