#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

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
    string a, b;
    cin >> a >> b;
    int cnt0 = 0, cnt1 = 0;
    int bal0 = 0, bal1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') cnt1++;
        else cnt0++;
        if (a[i] == '0' && b[i] == '0') {
            bal0++;
        }
        if (a[i] == '1' && b[i] == '0') {
            bal1++;
        }
    }
    cout << bal0 * cnt1 + bal1 * cnt0 - bal0 * bal1 << endl;
    return 0;
}