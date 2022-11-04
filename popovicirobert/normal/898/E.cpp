#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int INF = (int) 1e9;
const int MAXN = (int) 2e5;

pair <int, int> v[MAXN + 1];

inline int check(int x) {
    int rez = 0;
    for(int pas = 1 << 15; pas; pas >>= 1)
        if((rez + pas) * (rez + pas) <= x)
           rez += pas;
    return rez;
}

bool cmp(pair <int, int> a, pair <int, int> b) {
    return a.first - a.second < b.first - b.second;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x;
        int x0 = check(x);
        v[i].first = min(x - x0 * x0, (x0 + 1) * (x0 + 1) - x);
        int a = x;
        while(check(a) * check(a) == a) {
            a++;
        }
        int b = x;
        while(b >= 0 && check(b) * check(b) == b) {
            b--;
        }
        if(b < 0)
            b = -INF;
        v[i].second = min(a - x, x - b);
    }
    sort(v + 1, v + n + 1, cmp);
    ll ans = 0;
    for(i = 1; i <= n / 2; i++) {
        ans += v[i].first;
    }
    for(i = n / 2 + 1; i <= n; i++) {
        ans += v[i].second;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}