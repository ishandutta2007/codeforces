#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 2 * 1010;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
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
        int l = -1, r = N;
        while(r - l > 1){
            int mid = (r + l) / 2;
            vector<int> good(mid + 1, 1);
            for (int i = 0; i < n; i++){
                vector<int> goodd(mid + 1);
                for (int j = 0; j <= mid; j++){
                    if (!good[j]) continue;
                    if (j + a[i] <= mid) goodd[j + a[i]] |= 1;
                    if (j - a[i] >= 0) goodd[j - a[i]] |= 1;
                }
                good = goodd;
            }
            bool x = 0;
            for (int i = 0; i <= mid; i++){
                if (good[i]){
                    x = 1;
                }
            }
            if (x) r = mid;
            else l = mid;
        }
        cout << r << endl;
    }
    return 0;
}