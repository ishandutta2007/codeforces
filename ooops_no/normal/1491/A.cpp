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
    int n, q;
    cin >> n >> q;
    int cnt = 0, cnt1 = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] == 0) cnt++;
        else cnt1++;
    }
    for (int i = 0; i < q; i++){
        int t;
        cin >> t;
        if (t == 1){
            int x;
            cin >> x;
            x--;
            if (a[x] == 0) cnt--, cnt1++;
            else cnt++, cnt1--;
            a[x] = 1 - a[x];
        }
        else{
            int k;
            cin >> k;
            if (cnt1 >= k) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}