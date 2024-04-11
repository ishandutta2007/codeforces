#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;

using namespace std;

struct pt {
    ll x, y;
    void scan() {
        scanf("%lld%lld", &x, &y);
    }
    pt operator-(const pt &p) const {
        return {x - p.x, y - p.y};
    }
    pt operator+(pt &p) {
        return {x + p.x, y + p.y};
    }
    ll operator*(pt p) {
        return x * p.y - y * p.x;
    }
    ll operator%(pt &p) {
        return x * p.x + y * p.y;
    }
    ll pr(pt p1, pt p2) {
        return (p1 - *this) * (p2 - *this);
    }
    ll len() {
        return *this % *this;
    }
    bool operator<(pt p) {
        ll pp = *this * p;
        if (pp)
            return pp > 0;
        return len() < p.len();
    }
};

int n[2];
vector<pt> a[2], b[2];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d", &n[0], &n[1]);
    for (int t = 0; t < 2; t++) {
        a[t].resize(n[t]);
        for (int i = 0; i < n[t]; i++) {
            a[t][i].scan();
            if (make_pair(a[t][i].x, a[t][i].y) < make_pair(a[t][0].x, a[t][0].y))
                swap(a[t][i], a[t][0]);
        }
        pt f = a[t][0];
        sort(a[t].begin() + 1, a[t].end(), [f](pt &p1, pt &p2) {return p1 - f < p2 - f;});
        for (int i = 0; i < n[t]; i++) {
            while (b[t].size() > 1 && b[t][b[t].size() - 2].pr(b[t].back(), a[t][i]) <= 0)
                b[t].pop_back();
            b[t].push_back(a[t][i]);
        }
    }
    if (b[0].size() != b[1].size()) {
        printf("NO");
        return 0;
    }
    vector<ll> c;
    int m = b[0].size();
    for (int i = 0; i < 3; i++) {
        int t = min(i, 1);
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < 3; j++)
                c.push_back((b[t][(i + j) % m] - b[t][i]).len());
        }
    }
    int k = c.size();
    vector<int> z(k);
    for (int i = 1, l = 0, r = 0; i < k; i++) {
        z[i] = max(min(r - i + 1, z[i - l]), 0);
        while (i + z[i] < k && c[z[i]] == c[i + z[i]])
            z[i]++;
        if (r < i + z[i] - 1) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    for (int i = m * 2; i < m * 4; i += 2)
        if (z[i] >= m * 2) {
            printf("YES\n");
            return 0;
        }
    printf("NO\n");
}