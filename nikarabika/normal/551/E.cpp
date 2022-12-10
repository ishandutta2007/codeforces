#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

const int maxn = 500 * 1000,
      SQRT = 500,
      maxbox = 1000 + 5;
unordered_map<LL, short> cnt[maxbox];
LL a[maxn];
LL lazy[maxbox];
int n, q;

void add(int box, int pos, int val) {
    short newval = --cnt[box][a[pos]];
    if (newval == 0) cnt[box].erase(a[pos]);
    a[pos] += val;
    cnt[box][a[pos]]++;
}

void relax(int box) {
    cnt[box].clear();
    int start = box * SQRT;
    int end = start + SQRT;
    for (int i = start; i < end; i++) {
        a[i] += lazy[box];
        cnt[box][a[i]]++;
    }
    lazy[box] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[i / SQRT][a[i]]++;
    }
    for (int _ = 0; _ < q; _++) {
        int ty, fi, se, val;
        cin >> ty >> fi;
        if (ty == 1) {
            cin >> se >> val;
            fi--;
            if (fi % SQRT) {
                int box = fi / SQRT;
                relax(box);
                while (fi % SQRT and fi < se) {
                    add(box, fi, val);
                    fi++;
                }
            }
            if (se > fi and se % SQRT) {
                int box = se / SQRT;
                relax(box);
                while (se % SQRT) {
                    se--;
                    add(box, se, val);
                }
            }
            for (int box = fi / SQRT; box < se / SQRT; box++)
                lazy[box] += val;
        }
        else {
            val = fi;
            int le = maxbox,
                ri = -1;
            for (int i = 0; i < maxbox; i++)
                if (cnt[i].count(fi - lazy[i]) and cnt[i].at(fi - lazy[i]))
                    smin(le, i), smax(ri, i);
            if (ri == -1)
                cout << -1 << '\n';
            else {
                int start = le * SQRT;
                int end = start + SQRT;
                int left_idx, right_idx;
                for (int i = start; i < end; i++)
                    if (a[i] + lazy[le] == val) {
                        left_idx = i;
                        break;
                    }
                start = ri * SQRT;
                end = start + SQRT;
                for (int i = end - 1; i >= start; i--)
                    if (a[i] + lazy[ri] == val) {
                        right_idx = i;
                        break;
                    }
                cout << right_idx - left_idx << '\n';
            }
        }
    }
    return 0;
}