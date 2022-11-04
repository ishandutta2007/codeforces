#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

int arr[MAXN + 1];
pair <ll, int> aib[MAXN + 1];

inline void update(int pos, int n, pair <int, int> cur) {
    for(int i = pos; i <= n; i += lsb(i)) {
        aib[i].first += cur.first;
        aib[i].second += cur.second;
    }
}

inline pair <ll, int> query(int pos) {
    pair <ll, int> ans = {0, 0};
    for(int i = pos; i > 0; i -= lsb(i)) {
        ans.first += aib[i].first;
        ans.second += aib[i].second;
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ll T;
    ios::sync_with_stdio(false);
    cin >> n >> T;
    ll s = 0;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        s += arr[i];
        update(i, n, {arr[i], 1});
    }
    ll ans = 0;
    int cnt = n;
    while(cnt > 0) {
        ans += 1LL * cnt * (T / s);
        T %= s;
        int pos = 1;
        while((T < s && cnt > 0) || pos != 1) {
            pair <ll, int> aux = query(pos - 1);
            int res = pos - 1;
            for(int step = 1 << 17; step; step >>= 1) {
                if(res + step <= n) {
                    pair <ll, int> cur = query(res + step);
                    if(cur.first - aux.first <= T) {
                        res += step;
                    }
                }
            }
            res++;
            if(res - 1 >= pos) {
                pair <ll, int> cur = query(res - 1);
                T -= cur.first - aux.first;
                ans += cur.second - aux.second;
            }
            if(res <= n) {
                update(res, n, {-arr[res], -1});
                s -= arr[res];
                cnt--;
            }
            pos = res;
            if(pos > n) {
                pos = 1;
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}