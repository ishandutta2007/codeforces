#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        int sum = 0, sum1 = 0, mx = 0;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            sum += v[i];
            sum1 += v[i];
            mx = max(mx, v[i]);
        }
        if (sum % (n - 1) == 0){
            sum = sum / (n - 1);
        }
        else{
            sum = sum / (n - 1) + 1;
        }
        cout << max(mx, sum) * (n - 1) - sum1 << endl;
    }
    return 0;
}