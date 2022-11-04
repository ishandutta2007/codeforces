#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

int a[MAXN + 1];

inline int get(int x, int y) {
    return abs(x - y);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 1e9;
    int id;
    for(i = 1; i <= 100; i++) {
        int cur = 0;
        for(j = 1; j <= n; j++) {
            cur += min(get(i, a[j]), min(get(i, a[j] - 1), get(i, a[j] + 1)));
        }
        if(ans > cur) {
            ans = cur;
            id = i;
        }
    }
    cout << id << " " << ans;
    //cin.close();
    //cout.close();
    return 0;
}