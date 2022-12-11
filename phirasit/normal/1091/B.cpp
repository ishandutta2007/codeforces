#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

using pii = pair<int, int>;

set<pii> data;
int x[N], y[N], a[N], b[N];
int n;

int test(int X, int Y) {
    for (int i = 1; i <= n; ++i) {
        int px = X - a[i], py = Y - b[i];
        if (data.find({px, py}) == data.end()) {
            return 0;
        }
    }

    return 1;
}

int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        data.insert({x[i], y[i]});
    }

    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= n; ++i) {
        if (test(x[1] + a[i], y[1] + b[i])) {
            cout << (x[1] + a[i]) << " " << (y[1] + b[i]) << endl;
            return 0;
        }
    }

    return 0;
}