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
    vector<int> cnt(30);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        int mx = 0;
        for (int j = 0; j < 30; j++){
            if (a[i] & (1 << j)){
                mx = j;
            }
        }
        cnt[mx]++;
    }
    if (*max_element(cnt.begin(), cnt.end()) >= 3){
        cout << 1 << endl;
        return 0;
    }
    int ans = 1e18;
    for (int i = 0; i + 1 < n; i++){
        for (int k = i + 1; k < n; k++){
            for (int j = i; j >= 0; j--){
                int first_val = 0, second_val = 0;
                for (int f = i + 1; f <= k; f++) first_val ^= a[f];
                for (int f = i; f >= j; f--) second_val ^= a[f];
                if (first_val < second_val){
                    ans = min(ans, k - j - 1);
                }
            }
        }
    }
    cout << (ans == 1e18 ? -1 : ans) << endl;
    return 0;
}