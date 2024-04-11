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
    int t;
    cin >> t;
    while(t--){
        vector<int> v(4);
        for (int i = 0; i < 4; i++) cin >> v[i];
        int f = max(v[0], v[1]), s = max(v[2], v[3]);
        sort(v.rbegin(), v.rend());
        if (v[0] == max(f, s) && v[1] == min(f, s)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}