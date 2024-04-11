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
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int mn = *min_element(a.begin(), a.end()), cnt = 0;
    for (auto to : a){
        if (to == mn) cnt++;
    }
    cout << (cnt > n / 2 ? "Bob" : "Alice") << endl;
    return 0;
}