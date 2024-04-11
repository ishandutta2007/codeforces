#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int cnt = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            while(a[i] % 2 == 0){
                a[i] /= 2;
                cnt++;
            }
        }
        sort(a.rbegin(), a.rend());
        for (int i = 0; i < cnt; i++){
            a[0] *= 2;
        }
        int sum = 0;
        for (auto to : a) sum += to;
        cout << sum << endl;
    }
    return 0;
}