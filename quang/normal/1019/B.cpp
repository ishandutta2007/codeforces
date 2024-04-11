#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

void answer(int u) {
    printf("! %d\n", u);
    fflush(stdout);
}

int ask(int u) {
    printf("? %d\n", u);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

bool inside(int u, pair<int, int> v) {
    return ((u > v.first) ^ (u >= v.second)) == 1;
}

bool check(pair<int ,int> u, pair<int, int> v) {
    if (inside(u.first, v) && inside(u.second, v)) {
        return 1;
    }
    if (inside(v.first, u) && inside(v.second, u)) {
        return 1;
    }
    if (inside(u.first, v) && inside(v.first, u)) {
        return 1;
    }
    if (inside(u.second, v) && inside(v.second, u)) {
        return 1;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    if ((n / 2) % 2 != 0) {
        answer(-1);
        return 0;
    }
    int x = ask(1);
    int y = ask(1 + n / 2);
    if (x == y) {
        answer(1);
        return 0;
    }
    pair<int, int> u(x, y);
    pair<int, int> v(y, x);
    int low = 1, high = n / 2 + 1;
    while (high - low > 1) {
        int mid = (high + low) / 2;
        // printf("%d %d %d aa\n", low, high, mid);
        // fflush(stdout);
        int foo = ask(mid);
        int bar = ask(mid + n / 2);
        if (foo == bar) {
            answer(mid);
            return 0;
        }
        pair<int, int> a(u.first, foo);
        pair<int, int> b(v.first, bar);
        // cout << a.first << " " << a.second << endl;
        // cout << b.first << " " << b.second << endl;
        if (check(a, b)) {
            // cout << "high" << endl;
            high = mid;
            u = a;
            v = b;
        } else {
            low = mid;
            u = make_pair(foo, u.second);
            v = make_pair(bar, v.second);
        }
    }
    answer(low);
    return 0;
}