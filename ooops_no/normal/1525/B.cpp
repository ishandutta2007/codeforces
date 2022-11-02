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
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        if (is_sorted(a.begin(), a.end())){
            cout << 0 << endl;
        }
        else if (a[0] == 1 || a[n - 1] == n){
            cout << 1 << endl;
        }
        else{
            if (a[0] == n && a[n - 1] == 1){
                cout << 3 << endl;
            }
            else{
                cout << 2 << endl;
            }
        }
    }
    return 0;
}