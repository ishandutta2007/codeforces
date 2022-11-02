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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        if (n % 2 == 0){
            for (int i = 0; i < n; i += 2){
                cout << a[i + 1] << ' ' << -a[i] << ' ';
            }
            cout << endl;
        }
        else{
            for (int i = 0; i + 3 < n; i += 2){
                cout << a[i + 1] << ' ' << -a[i] << ' ';
            }
            if (a[n - 2] + a[n - 1] != 0){
                cout << a[n - 2] + a[n - 1] << ' ' << -a[n - 3] << ' ' << -a[n - 3] << endl;
            }
            else if (a[n - 3] + a[n - 2] != 0){
                cout << -a[n - 1] << " " << -a[n - 1] << " " << a[n - 3] + a[n - 2] << endl;
            }
            else{
                cout << -a[n - 2] << ' ' << a[n - 3] + a[n - 1] << ' ' << -a[n - 2] << endl;
            }
        }
    }
    return 0;
}