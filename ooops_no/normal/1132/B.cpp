#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    vector<int> v(x);
    int sum = 0;
    for (int i = 0; i < x; i++){
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end(), greater <int>());
    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        cout << sum - v[a - 1] << " ";
    }
}