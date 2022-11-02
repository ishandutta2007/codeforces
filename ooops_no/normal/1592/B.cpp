#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x, n;
        cin >> n >> x;
        vector<int> a(n), b;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        b = a;
        sort(b.begin(), b.end());
        bool f = 1;
        for (int i = 0; i < n; i++){
            if (i - x >= 0 || i + x < n) continue;
            f &= b[i] == a[i];
        }
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}