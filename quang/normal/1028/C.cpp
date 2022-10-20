#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;

struct Rec {
    int x, xx, y, yy;

    Rec(int x = 0, int y = 0, int xx = 0, int yy = 0) : x(x), y(y), xx(xx), yy(yy) {}
} a[N];

vector<pair<int, int> > b, c;
vector<int> X, Y;

bool check(int x, int y) {
    int cur = 0;
    for (int i = 1; i <= n && cur < 2; i++) {
        if (x >= a[i].x && x <= a[i].xx && y >= a[i].y && y <= a[i].yy) {
            continue;
        }
        cur++;
    }
    return cur < 2;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &a[i].x, &a[i].y, &a[i].xx, &a[i].yy);
        b.emplace_back(a[i].x, 1);
        b.emplace_back(a[i].xx + 1, -1);
        c.emplace_back(a[i].y, 1);
        c.emplace_back(a[i].yy + 1, -1);
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int cur = 0;
    for (int i = 0, j = 0; i < b.size(); i = j) {
        while (j < b.size() && b[j].first == b[i].first) {
            cur += b[j].second;
            j++;
        }
        if (cur >= n - 1) {
            X.push_back(b[i].first);
        }
    }
    cur = 0;
    for (int i = 0, j = 0; i < c.size(); i = j) {
        while (j < c.size() && c[j].first == c[i].first) {
            cur += c[j].second;
            j++;
        }
        if (cur >= n - 1) {
            Y.push_back(c[i].first);
        }
    }
    for (int xxx : X) {
        for (int yyy : Y) {
            if (check(xxx, yyy)) {
                cout << xxx << " " << yyy << endl;
                return 0;
            }
        }
    }
    return 0;
}