#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int d[maxN];

void solve() {
    int n;
    cin >> n;
    vector<int> p;
    for (int i = 2; i <= n; ++i) {
        if (!d[i]) {
            p.push_back(i);
            for (int j = i; j <= n; j += i) d[j] = 1;
        }
    }
    int x = 1;
    int op = 0;
    int cnt = 10000;
    for (auto &w: p) {
        if (1ll * x * w * w > n || 1ll * w * w > n) break;
        op++;
        cout << "B " << w << endl;
        cnt -= 1;
        int e;
        cin >> e;
        if (e) {
            cout << "A " << w << endl;
            cin >> e;
            cnt--;
            if (e) {
                int l = 1, r = 17;
                while (r - l > 1) {
                    int mid = (r + l) / 2;
                    int st = 1;
                    bool bad = false;
                    range(_, mid) {
                        st *= w;
                        if (1ll * x * st > n) {
                            r = mid;
                            bad = true;
                            break;
                        }
                    }
                    if (bad) continue;
                    cout << "A " << st << endl;
                    cnt--;
                    cin >> e;
                    if (e) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
                range(_, l) x *= w;
            }
        }
    }
    vector<int> obl;
    for (int i = op; i < (int) p.size(); ++i) {
        if (1ll * p[i] * x > n) break;
        obl.push_back(p[i]);
    }
    int step = 0;
    int numbers;
    cout << "A 1" << endl;
    cin >> numbers;
    range(i, (int) obl.size()) {
        if (1ll * obl[i] * x > n) break;
        cout << "B " << obl[i] << endl;
        int e;
        cin >> e;
        numbers -= e;
        step++;
        if (step == 100) {
            cout << "A 1" << "\n";
            int cnumbers;
            cin >> cnumbers;
            if (numbers != cnumbers) {
                for (int w = i; w > i - 100; --w) {
                    cout << "A " << obl[w] << endl;
                    cin >> e;
                    if (e) {
                        x *= obl[w];
                        cout << "C " << x << endl;
                        return;
                    }
                }
            }
            step = 0;
        }
    }
    cout << "A 1" << "\n";
    int cnumbers;
    cin >> cnumbers;
    if (numbers != cnumbers) {
        int i = (int)obl.size() - 1;
        int e;
        for (int w = i; w > i - 100; --w) {
            cout << "A " << obl[w] << endl;
            cin >> e;
            if (e) {
                x *= obl[w];
                cout << "C " << x << endl;
                return;
            }
        }
    }
    cout << "C " << x << "\n";
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}