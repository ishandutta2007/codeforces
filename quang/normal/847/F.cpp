#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, k, m, a;
int num[N], last[N], id[N];
int res[N];

bool cmp(int u, int v) {
    if (num[u] != num[v]) {
        return num[u] > num[v];
    }
    return last[u] < last[v];
}

bool check3(int u) {
    int pos = id[u];
    pair<int, int> foo = make_pair(num[pos] + m - a, -m);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == u) {
            continue;
        }
        pair<int, int> bar = make_pair(num[id[i]], -last[id[i]]);
        cnt += (bar > foo);
    }
    return cnt < k && foo.first > 0;
}

bool check1(int u) {
    if (num[id[u]] == 0) {
        return 0;
    }
    int val = num[id[u]];
    int v = m - a;
    int L = last[id[u]];
    int cnt = 0;
    for (int i = 1; i <= n && v > 0; i++) {
        if (i == u) {
            continue;
        }
        if (num[id[i]] > val) {
            cnt++;
            continue;
        }
        if (num[id[i]] == val && last[id[i]] < L) {
            cnt++;
            continue;
        }
        int need = val + 1 - num[id[i]];
        if (need <= v) {
            v -= need;
            cnt++;
            continue;
        } else {
            break;
        }
    }
    return cnt < k;
}

int main() {
    scanf("%d %d %d %d", &n, &k, &m, &a);
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= a; i++) {
        int u;
        scanf("%d", &u);
        num[u]++;
        last[u] = i;
    }
    for (int i = 1; i <= n; i++) {
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    if (a == m) {
        for (int i = 1; i <= n; i++) {
            if (i <= k && num[id[i]] > 0) {
                res[id[i]] = 1;
            } else {
                res[id[i]] = 3;
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", res[i]);
        }
        return 0;
    }
//    for (int i = 1; i <= n; i++) {
//        cout << id[i] << " ";
//    }
    for (int i = 1; i <= n; i++) {
        if (!check3(i)) {
            res[id[i]] = 3;
            continue;
        }
        if (check1(i)) {
            res[id[i]] = 1;
            continue;
        }
        res[id[i]] = 2;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}