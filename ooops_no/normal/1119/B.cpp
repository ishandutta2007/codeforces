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
    int n, h;
    cin >> n >> h;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int l = 0, r = n + 1;
    while(l < r - 1){
        int mid = (l + r) / 2, a = 0, sm = 0;
        vector<int> v1;
        for (int i = 0; i < mid; i++){
            v1.pb(v[i]);
        }
        sort(v1.begin(), v1.end());
        reverse(v1.begin(), v1.end());
        for (int i = 0; i < mid; i++){
            if (i % 2 == 0){
                a = v1[i];
            }
            else{
                sm += max(a, v1[i]);
                a = 0;
            }
        }
        if (a != 0){
            sm += a;
        }
        if (sm <= h){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    int sm = 0, a = 0;
    vector<int> v1;
    for (int i = 0; i < r; i++){
        v1.pb(v[i]);
    }
    sort(v1.begin(), v1.end());
    reverse(v1.begin(), v1.end());
    for (int i = 0; i < r; i++){
        if (i % 2 == 0){
            a = v1[i];
        }
        else{
            sm += max(a, v1[i]);
            a = 0;
        }
    }
    if (a != 0){
        sm += a;
    }
    if (sm <= h){
        cout << r;
    }
    else{
        cout << l;
    }
}