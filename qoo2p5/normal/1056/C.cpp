#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

bool mini(auto& x, const auto& y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

bool maxi(auto& x, const auto& y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const int N = (int) 2e4 + 100;

int n, m;
int p[N];
int who[N];
vector<pair<int, int>> cool;
bool used[N];
int last = 0;

void choose(int x) {
    cout << x << endl;
    used[x] = true;
}

void we() {
    if (last && who[last] && !used[who[last]]) {
        choose(who[last]);
        return;
    }

    while (!cool.empty()) {
        auto it = cool.back();
        if (used[it.first]) {
            assert(used[it.second]);
            cool.pop_back();
            continue;
        }
        break;
    }

    if (cool.empty()) {
        int best = -1;
        for (int i = 1; i <= 2 * n; i++) {
            if (!used[i] && (best == -1 || p[i] > p[best])) {
                best = i;
            }
        }
        choose(best);
    } else {
        choose(cool.back().first);
    }
}

void enemy() {
    int x;
    cin >> x;
    used[x] = true;
    last = x;
}

void run() {
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        who[a] = b;
        who[b] = a;
        if (p[a] < p[b]) swap(a, b);
        cool.emplace_back(a, b);
    }
    int t;
    cin >> t;
    for (int i = 0; i < 2 * n; i++) {
        if (t == 1) {
            we();
        } else {
            enemy();
        }
        t = 3 - t;
    }
}