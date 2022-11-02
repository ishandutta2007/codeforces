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
    vector<int> a(n);
    vector<int> st(51, -1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (st[a[i]] == -1) st[a[i]] = i + 1;
    }
    for (int i = 0; i < q; i++){
        int b;
        cin >> b;
        cout << st[b] << ' ';
        for (int j = 1; j <= 50; j++){
            if (st[b] > st[j]) st[j]++;
        }
        st[b] = 1;
    }
    return 0;
}