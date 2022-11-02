#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll __int128

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

bool solve(){
    int u, r, d, l, n;
    cin >> n >> u >> r >> d >> l;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                for (int q = 0; q < 2; q++){
                    int uu = u, rr = r, dd = d, lq = l;
                    if (i){
                        uu--, lq--;
                    }
                    if (j){
                        uu--, rr--;
                    }
                    if (k){
                        rr--, dd--;
                    }
                    if (q){
                        dd--, lq--;
                    }
                    if (uu >= 0 && rr >= 0 && dd >= 0 && lq >= 0 && uu <= n - 2 && rr <= n - 2 && dd <= n - 2 && lq <= n - 2){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

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
        if (solve()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}