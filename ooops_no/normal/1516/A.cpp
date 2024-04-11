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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++){
            if (k >= a[i]){
                k -= a[i];
                a[n - 1] += a[i];
                a[i] = 0;
            }
            else{
                a[i] -= k;
                a[n - 1] += k;
                break;
            }
        }
        for (auto to : a){
            cout << to << ' ';
        }
        cout << endl;
    }
    return 0;
}