#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e15 + 7;
const int N = 500;

void run() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int res = 0, all_cnt = a[0] == 0;

    for (int i = 1; i < n; ++i) {
        all_cnt += (a[i] == 0);
        a[i] += a[i-1];
    }
    if (abs(a[n-1]) > k*all_cnt) {
        cout << -1 << endl;
        return;
    }

    for (int B = 0; B < n; ++B) {
        int sum = 0, mn = inf, mx = -inf, cnt = all_cnt;

        for (int i = 0; i < n; ++i) {
            if ((i == 0 && a[i] == 0) || (i && a[i] == a[i-1])) {
                //-(cnt-1)*k - (a[n-1] + sum) <= + x <= (cnt-1)*k - (a[n-1] + sum);
                int val = a[n-1] + sum;
                int take;
                if (i <= B) {
                    take = min((cnt-1)*k - val, k);
                } else {
                    take = max(-(cnt-1)*k - val, -k);
                }
                sum += take;
                --cnt;
            }

            chmin(mn, a[i] + sum);
            chmax(mx, a[i] + sum);
        }
        chmax(res, mx-mn+1);
    }

    for (int i = 0; i < n; ++i)
        a[i] = -a[i];
    
    for (int B = 0; B < n; ++B) {
        int sum = 0, mn = inf, mx = -inf, cnt = all_cnt;

        for (int i = 0; i < n; ++i) {
            if ((i == 0 && a[i] == 0) || (i && a[i] == a[i-1])) {
                //-(cnt-1)*k - (a[n-1] + sum) <= + x <= (cnt-1)*k - (a[n-1] + sum);
                int val = a[n-1] + sum;
                int take;
                if (i <= B) {
                    take = min((cnt-1)*k - val, k);
                } else {
                    take = max(-(cnt-1)*k - val, -k);
                }
                sum += take;
                --cnt;
            }

            chmin(mn, a[i] + sum);
            chmax(mx, a[i] + sum);
        }
        chmax(res, mx-mn+1);
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}