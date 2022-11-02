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
        n *= 2;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        while(1){
            random_shuffle(a.begin(), a.end());
            bool x = 0;
            for (int i = 0; i < n; i++){
                int l = (i - 1 + n) % n, r = (i + 1) % n;
                if (a[i] * 2 == (a[l] + a[r])){
                    x = 1;
                    break;
                }
            }
            if (!x){
                for (auto to : a){
                    cout << to << ' ';
                }
                cout << endl;
                break;
            }
        }
    }
    return 0;
}