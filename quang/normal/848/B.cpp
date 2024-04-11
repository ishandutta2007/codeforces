#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, w, h;

struct data {
    int g, p, t, id;
    pair<int, int> a;
} a[N], b[N];

bool cmp(data u, data v) {
    if (u.p - u.t != v.p - v.t) {
        return u.p - u.t < v.p - v.t;
    }
    if (u.g != v.g) {
        return u.g > v.g;
    }
    if (u.g == 2) {
        return u.p > v.p;
    }
    return u.p < v.p;
}

bool cmp1(data u, data v) {
    if (u.g != v.g) {
        return u.g < v.g;
    }
    if (u.g == 1) {
        return u.p < v.p;
    }
    return u.p > v.p;
}

pair<int, int> res[N];

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &n, &w, &h);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a[i].g, &a[i].p, &a[i].t);
        a[i].id = i;
        if (a[i].g == 1) {
            a[i].a = make_pair(a[i].p, h);
        } else {
            a[i].a = make_pair(w, a[i].p);
        }
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        int last = i;
        while (last < n && a[i].p - a[i].t == a[last + 1].p - a[last + 1].t) {
            last++;
        }
        for (int j = i; j <= last; j++) {
            b[j] = a[j];
        }
        sort(b + i, b + last + 1, cmp1);
        for (int j = i; j <= last; j++) {
            res[a[j].id] = b[j].a;
        }
        i = last;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}