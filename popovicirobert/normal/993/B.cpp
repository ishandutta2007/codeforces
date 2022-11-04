#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

pair <int, int> a[20], b[20];
int cnt[10];

int sum, id;
bool flag = 1;

inline int check(pair <int, int> *a, pair <int, int> *b, int n, int m) {
    int i, j;
    memset(cnt, 0, sizeof(cnt));
    for(i = 1; i <= n; i++) {
        bool vis[10];
        memset(vis, 0, sizeof(vis));
        for(j = 1; j <= m; j++) {
            if(a[i].first == b[j].first && a[i].second == b[j].second)
                continue;
            if(a[i].first == b[j].first) {
                cnt[a[i].first]++;
                vis[a[i].first] = 1;
            }
            if(a[i].first == b[j].second) {
                cnt[a[i].first]++;
                vis[a[i].first] = 1;
            }
            if(a[i].second == b[j].second) {
                cnt[a[i].second]++;
                vis[a[i].second] = 1;
            }
            if(a[i].second == b[j].first) {
                cnt[a[i].second]++;
                vis[a[i].second] = 1;
            }
        }
        int nr = 0;
        for(j = 1; j <= 9; j++) {
            nr += vis[j];
        }
        if(nr > 1)
            flag = 0;
    }
    for(i = 1; i <= 9; i++) {
        sum += cnt[i] > 0;
        if(cnt[i])
            id = i;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        if(a[i].first > a[i].second)
            swap(a[i].first, a[i].second);
    }
    for(i = 1; i <= m; i++) {
        cin >> b[i].first >> b[i].second;
        if(b[i].first > b[i].second)
            swap(b[i].first, b[i].second);
    }
    check(b, a, m, n);
    check(a, b, n, m);
    if(sum == 2 && flag == 1) {
        cout << id;
    }
    else if(flag) {
        cout << 0;
    }
    else {
        cout << -1;
    }
    //cin.close();
    //cout.close();
    return 0;
}