#include <bits/stdc++.h>

using namespace std;

#define int long long

#define pb push_back

#define mp make_pair

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a = n, mx = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++){
        if (v[i] != v[0]){
            mx = max(mx, i);
            a = min(a, i);
        }
        else{
            mx = max(mx, i - a);
        }
    }
    cout << mx;
}