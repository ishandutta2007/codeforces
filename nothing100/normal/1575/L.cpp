#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
int a[200100];

const int M = 600010;
int tr[M + 10];
const int BIAS = 200001;

void upd(int &x, int y) {
    x = max(x, y);
}
int lowbit(int x) {
    return x & -x;
}
void add(int x, int y) {
    x += BIAS;
    while(x <= M) {
        upd(tr[x], y);
        x += lowbit(x);
    }
}
void clear(int x) {
    x += BIAS;
    while(x <= M) {
        tr[x] = -1e9;
        x += lowbit(x);
    }
}
int get(int x) {
    x += BIAS;
    int ret = -1e9;
    while(x) {
        upd(ret, tr[x]);
        x -= lowbit(x);
    }
    return ret;
}
int dp[200010];

void solve(int L, int R) {
    if (L >= R) return;
    int mid = (L + R) / 2;
    solve(L, mid);
    vector<int> p;
    for (int i = L; i <= R; i++) p.push_back(i);
    sort(p.begin(), p.end(), [&](int id1, int id2) {
        if (a[id1] == a[id2]) return id1 < id2;
        return a[id1] < a[id2];
    });
    for (auto &idx : p) {
        if (idx <= mid) {
            add(idx - a[idx] + 1, dp[idx]);
        } else {
            if (a[idx] < 0) continue;
            upd(dp[idx], get(idx - a[idx]) + 1);
        }
    }
    for (int i = L; i <= mid; i++) {
        clear(i - a[i] + 1);
    }
    //add(1, 0);
    solve(mid + 1, R);
}

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
        a[i] = i - a[i];
    }
    int ans = 0;
    for (int i = 0; i <= M; i++) {
        tr[i] = -1e9;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = -1e9;
    }
    //add(1, 0);
    solve(0, n);
    for (int i = 1; i <= n; i++) {
        //printf("dp[%d] = %d\n",i,dp[i]);
        upd(ans, dp[i]);
    }
    printf("%d\n",ans);
}