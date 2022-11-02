#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

int solve(int n, vector<int> a, vector<int> b){
    int l = 0, r = n + 1;
    while(r - l > 1){
        int mid = (r + l) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (a[i] + 1 + b[i] >= mid){
                if (cnt <= b[i] && mid - (cnt + 1) <= a[i]){
                    cnt++;
                }
            }
        }
        if (cnt >= mid) l = mid;
        else r = mid;
    }
    return l;
}

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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
        }
        cout << solve(n, a, b) << endl;
    }
    return 0;
}