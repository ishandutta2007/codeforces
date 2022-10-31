#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

const int INF = 1e9;

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
        vector<int> b(n);
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        int l = 0, r = 4e14 + 100;
        while(r - l > 1){
            int mid = (r + l) / 2;
            vector<int> a(n);
            for (int i = 0; i < n; i++){
                a[(i + 1) % n] = min(INF, (b[(i + 1) % n] - mid - b[i]) / (-n));
            }
            vector<int> bb(n);
            int now_sum = 0, total_sum = 0;
            for (int i = 0; i < n; i++){
                now_sum += (n - i + 1) * a[i];
                total_sum += a[i];
            }
            for (int i = 0; i < n; i++){
                now_sum -= a[i] * n;
                bb[i] = now_sum;
                now_sum += total_sum;
            }
            bool f = 0;
            for (int i = 0; i < n; i++){
                if (bb[i] > b[i]){
                    f = 1;
                }
            }
            if (f){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            a[(i + 1) % n] = min(INF, (b[(i + 1) % n] - l - b[i]) / (-n));
        }
        vector<int> bb(n);
        int now_sum = 0, total_sum = 0;
        for (int i = 0; i < n; i++){
            now_sum += (n - i + 1) * a[i];
            total_sum += a[i];
        }
        for (int i = 0; i < n; i++){
            now_sum -= a[i] * n;
            bb[i] = now_sum;
            now_sum += total_sum;
        }
        if (b == bb && *min_element(a.begin(), a.end()) > 0){
            cout << "YES\n";
            for (auto to : a){
                cout << to << ' ';
            }
            cout << endl;
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}