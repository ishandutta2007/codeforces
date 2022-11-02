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
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        int total_sum = 0;
        for (auto to : v) total_sum += to;
        if (total_sum == x){
            cout << "NO\n";
        }
        else{
            while(1){
                random_shuffle(v.begin(), v.end());
                int sum = 0;
                bool lol = 0;
                for (auto to : v){
                    sum += to;
                    if (sum == x) {
                        lol = 1;
                    }
                }
                if (!lol){
                    cout << "YES\n";
                    for (auto to : v){
                        cout << to << ' ';
                    }
                    cout << endl;
                    break;
                }
            }
        }
    }
    return 0;
}