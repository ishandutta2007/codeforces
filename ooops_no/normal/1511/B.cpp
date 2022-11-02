#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll __int128

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
        int a, b, c;
        cin >> a >> b >> c;
        int now = 1;
        for (int i = 0; i < c - 1; i++){
            now *= 10;
            now += 1;
        }
        int f = now, s = now;
        while(to_string(f).size() < a){
            f *= 3;
        }
        while(to_string(s).size() < b){
            s *= 5;
        }
        cout << f << " " << s << endl;
    }
    return 0;
}