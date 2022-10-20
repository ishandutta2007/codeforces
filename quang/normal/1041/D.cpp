#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int INF = 2e9;

int n, h;
int l[N], r[N];

int main() {
    scanf("%d %d", &n, &h);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", l + i, r + i);
    }
    int  res = 0;
    int cur = l[1];
    int curId = 0;
    l[n + 1] = INF;
    int curH = h;
    for (int i = 1; i <= n; i++) {
        while (curH > l[curId + 1] - cur) {
            curH -= l[curId + 1] - cur;
            cur = r[curId + 1];
            curId++;
        }
        cur += curH;
        curH = 0;
        res = max(res, cur - l[i]);
        if (i < n) {
            curH = l[i + 1] - r[i];
        }
    }
    cout << res << endl;
    return 0;
}