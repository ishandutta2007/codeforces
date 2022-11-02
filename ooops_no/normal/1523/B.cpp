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
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << n * 3 << endl;
        for (int i = 1; i < n; i += 2){
            cout << 1 << " " << i << " " << i + 1 << endl;
            cout << 1 << " " << i << " " << i + 1 << endl;
            cout << 2 << " " << i << " " << i + 1 << endl;
            cout << 1 << " " << i << " " << i + 1 << endl;
            cout << 1 << " " << i << " " << i + 1 << endl;
            cout << 2 << " " << i << " " << i + 1 << endl;
        }
    }
    return 0;
}