#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
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
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
    vector<int> x_xor(n), y_xor(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    for (int j = 0; j < n; j++){
        int now = 0;
        for (int i = n - 1; i > j; i--){
            a[i][j] ^= x_xor[i] ^ now;
            if (a[i][j]){
                x_xor[i] ^= 1;
                now ^= 1;
                b[i][j] ^= 1;
            }
        }
        a[j][j] ^= now;
    }
    for (int i = 0; i < n; i++){
        int now = 0;
        for (int j = n - 1; j > i; j--){
            a[i][j] ^= y_xor[j] ^ now;
            if (a[i][j]){
                y_xor[j] ^= 1;
                now ^= 1;
                b[i][j] ^= 1;
            }
        }
        a[i][i] ^= now;
    }
    for (int i = 0; i < n; i++){
        a[i][i] ^= x_xor[i] ^ y_xor[i];
        if (a[i][i]) b[i][i] ^= 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans += b[i][j];
    cout << ans << endl;
    return 0;
}