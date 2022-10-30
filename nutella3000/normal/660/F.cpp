#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e17 + 7;
const int max_n = 2e5 + 5;

struct line {
    int a, b;
    line(int a, int b): a(a), b(b) {}

    line() {}
};

struct seg {
    int l, r;
    seg(int l, int r): l(l), r(r) {}

    seg() {}

    bool operator<(seg b) {
        if (l == b.l) 
            return r < b.r;
        return l < b.l;
    }
};

int n;
int a[max_n], b[max_n];

struct comp {
    bool operator()(const int& o1, const int& o2)const {
        return a[o1] < a[o2];
    }
};

vector<line> hull;

double intersec(line a, line b) {
    if (a.a == b.a) return inf;
    double res = (double)(b.b - a.b) / (a.a - b.a);

    return res;
}

void add(line a) {
    while(hull.size() >= 2 && intersec(a, hull[hull.size() - 1]) < intersec(a, hull[hull.size() - 2]))
        hull.pop_back();

    hull.emplace_back(a);
}

int get(int x) {
    int l = -1;
    int r = hull.size() - 1;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if (x <= intersec(hull[mid], hull[mid + 1])) 
            r = mid;
        else
            l = mid;
    }

    //cout << r << " " << hull[r].b << endl;
    return hull[r].a * x + hull[r].b;
}


void scan() {
    cin >> n;
    n++;
    vector<int> c(n);
    for(int i = 0;i < n - 1;i++) 
        cin >> c[i];
    c[n - 1] = 0;

    for(int i = n - 1;i >= 0;i--) {
        a[i] += c[i];
        b[i] += c[i] * (i - (n - 1));

        if (i != n - 1) {
            a[i] += a[i + 1];
            b[i] += b[i + 1];
        }

    }
}

void solve() {
    scan();

    int res = 0;
    for(int i = 0;i < n;i++) {
        /*if (i == 0) {
            cout << b[i] + (n - i) * a[i] << endl;
        }*/

        add({i, b[i] + (n - i) * a[i]});
        res = max(res, get(a[i]) - b[i] - n * a[i]);
        /*if (i == 1) {
            cout << get(a[i]) << endl;
        }*/
        //cout << hull.size() << " " << hull[0].a << " " << hull[0].b << endl;
    }

    cout << res << endl;
}



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}