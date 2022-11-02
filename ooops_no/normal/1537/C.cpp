#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
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
        int n, j = 0;
        cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; i++) cin >> h[i];
        sort(h.begin(), h.end());
        for (int i = 0; i < n - 1; i++){
            if (h[i + 1] - h[i] < h[j + 1] - h[j]){
                j = i;
            }
        }
        for (int i = j; i < n; i++){
            if (i == j + 1) continue;
            cout << h[i] << " ";
        }
        for (int i = 0; i < j; i++){
            cout << h[i] << " ";
        }
        cout << h[j + 1] << " ";
        cout << endl;
    }
    return 0;
}