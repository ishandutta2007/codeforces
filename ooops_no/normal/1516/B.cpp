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
        vector<int> pr(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            if (i > 0){
                pr[i] = pr[i - 1] ^ a[i];
            }
            else{
                pr[i] = a[i];
            }
        }
        bool x = 0;
        for (int i = 0; i < n - 1; i++){
            if (pr[i] == (pr[n - 1] ^ pr[i])){
                x = 1;
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n - 1; j++){
                if ((pr[i] == (pr[j] ^ pr[i])) && (pr[i] == (pr[n - 1] ^ pr[j]))){
                    x = 1;
                }
            }
        }
        cout << (x ? "YES" : "NO") << endl;
    }
    return 0;
}