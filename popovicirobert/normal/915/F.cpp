#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 34

using namespace std;

const int MAXN = (int) 1e6;

vector <int> g[MAXN + 1];

pair <int, int> a[MAXN + 1];

int sef[MAXN + 1];
int sz[MAXN + 1];

int myfind(int x) {
    if(sef[x] == 0)
        return x;
    return sef[x] = myfind(sef[x]);
}

inline int myunion(int x, int y) {
    sz[x] += sz[myfind(y)];
    sef[myfind(y)] = x;
}

bool ok[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, y;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for(i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    sort(a + 1, a + n + 1);
    ll ans = 0;
    for(i = n; i >= 1; i--) {
        int nod = a[i].second;
        ok[nod] = 1;
        ll cnt = 0, sum = 0;
        sz[nod] = 1;
        for(auto it : g[nod]) {
            if(ok[it]) {
                cnt += sz[myfind(it)];
                cnt += 1LL * sz[myfind(it)] * sum;
                sum += sz[myfind(it)];
                myunion(nod, it);
            }
        }
        cnt++;
        ans -= 1LL * a[i].first * cnt;
    }
    memset(ok, 0, sizeof(ok));
    memset(sz, 0, sizeof(sz));
    memset(sef, 0, sizeof(sef));
    for(i = 1; i <= n; i++) {
        int nod = a[i].second;
        ok[nod] = 1;
        ll cnt = 0, sum = 0;
        sz[nod] = 1;
        for(auto it : g[nod]) {
            if(ok[it]) {
                cnt += sz[myfind(it)];
                cnt += 1LL * sz[myfind(it)] * sum;
                sum += sz[myfind(it)];
                myunion(nod, it);
            }
        }
        cnt++;
        ans += 1LL * a[i].first * cnt;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}