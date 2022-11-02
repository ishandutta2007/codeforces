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
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < n; j++){
            if (a[j] & (1 << i)){
                int sum = 0;
                for (int k = j + 2; k < n; k++){
                    sum += a[k - 1];
                    if (sum >= (1 << (i + 1))) break;
                    if (sum < (1 << i)) continue;
                    ans += (a[j] ^ a[k]) == sum;
                }
                sum = 0;
                for (int k = j - 2; k >= 0; k--){
                    sum += a[k + 1];
                    if (sum >= (1 << (i + 1))) break;
                    if (sum < (1 << i)) continue;
                    ans += (a[j] ^ a[k]) == sum;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}