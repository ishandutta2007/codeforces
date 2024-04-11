#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

map<int, int> masks;
int add(int num, int amount) {
    masks[num] |= 1 << amount;
    return 0;
}

unordered_map<int, int> mem;

int calc(int mask) {
    if (mask == 1 || mask == 0) {
        return 0;
    }
    if (mem.count(mask)) {
        return mem[mask];
    }
    int& val = mem[mask];

    vector<int> vals;
    for (int i = 1; i < 31; ++i) {
        if ((mask >> i)) {
            vals.puba(calc((mask & ((1 << i) - 1)) | (mask >> i)));
        }
    }
    sort(bend(vals));
    val = 0;
    for (int num : vals) {
        if (num < val) {
            continue;
        }
        if (num == val) {
            ++val;
            continue;
        }
        break;
    }
    return val;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        for (int j = 2; j * j <= num; ++j) {
            if (num % j == 0) {
                int cnt = 0;
                while (num % j == 0) {
                    ++cnt;
                    num /= j;
                }
                add(j, cnt);
            }
        }
        if (num != 1) {
            add(num, 1);
        }
    }

    int res = 0;
    for (auto p : masks) {
        res ^= calc(p.ss);
    }

    if (!res) {
        cout << "Arpa\n";
    } else {
        cout << "Mojtaba\n";
    }
    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}