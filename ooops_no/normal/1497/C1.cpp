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
        if (n == 4){
            cout << 1 << " " << 1 << " " << 2 << endl;
            continue;
        }
        if (n % 2 == 0){
            if (n % 4 == 2)
                cout << n / 2 - 1 << " " << n / 2 - 1 << " " << 2 << endl;
            else
                cout << n / 4 << ' ' << n / 4 << ' ' << n / 4 + n / 4 << endl;
        }
        else{
            cout << n / 2 << " " << n / 2 << " " << 1 << endl;
        }
    }
    return 0;
}