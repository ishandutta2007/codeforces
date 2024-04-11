#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
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
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (i - 1 >= 0){
                ans = max(ans, max(a[i], a[i - 1]) * min(a[i], a[i - 1]));
            }
        }
        cout << ans << endl;
    }
    return 0;
}