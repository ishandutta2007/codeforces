#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 2e5;

int a[MAXN + 1];
vector <int> divi[MAXN + 1], g[MAXN + 1];

pair <int, int> arr[MAXN + 1];

int myfind(int x) {
    if(arr[x].second == 0)
        return x;
    return arr[x].second = myfind(arr[x].second);
}

ll dp[MAXN + 1];
int now[MAXN + 1];
ll ans;

inline void myunion(int x, int y) {
    x = myfind(x), y = myfind(y);
    if(x != y) {
        arr[x].second = y;
        ans -= (1LL * arr[x].first * (arr[x].first - 1) / 2);
        ans -= (1LL * arr[y].first * (arr[y].first - 1) / 2);
        arr[y].first += arr[x].first;
        ans += (1LL * arr[y].first * (arr[y].first - 1) / 2);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, y;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        divi[a[i]].push_back(i);
    }
    for(i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i = 1; i <= n; i++) {
        arr[i] = {1, 0};
    }
    for(int val = 1; val <= MAXN; val++) {
        ans = 0;
        for(i = val; i <= MAXN; i += val) {
            ans += divi[i].size();
            for(auto it : divi[i]) {
                now[it] = val;
                for(auto nod : g[it]) {
                    if(now[nod] == val) {
                        myunion(it, nod);
                    }
                }
            }
        }
        dp[val] = ans;
        for(i = val; i <= MAXN; i += val) {
            for(auto it : divi[i]) {
                arr[it] = {1, 0};
            }
        }
    }
    for(i = MAXN; i >= 1; i--) {
        for(int j = 2 * i; j <= MAXN; j += i)
            dp[i] -= dp[j];
    }
    for(i = 1; i <= MAXN; i++) {
        if(dp[i] > 0) {
            cout << i << " " << dp[i] << "\n";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}