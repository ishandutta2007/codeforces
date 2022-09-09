#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <ll, ll> pii;
const int MAXN = 2e5 + 5;

int n, m;
vector <ll> arr;
ll inp[MAXN];
map <ll, ll> rev;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        ll num;
        scanf("%I64d", &num);
        inp[i] = num;
        rev[num] = i;
        arr.puba(num);
    }

    sort(bend(arr));

    for (int i = 0; i < m; ++i) {
        ll l, pos, dir;
        scanf("%I64d%I64d", &pos, &l);
        --pos;
        dir = 1;
        ll prev = -1;
        while (true) {
            //assert(l >= 0);
            //cerr << pos << " " << l << " " << dir << endl;
            if (dir == 1) {
                ll tmp = rev[arr[upper_bound(bend(arr), inp[pos] + l) - arr.begin() - 1]];
                if (tmp == pos && tmp == prev) {
                    break;
                }
                if (prev == tmp) {
                    ll q = l / abs(inp[tmp] - inp[pos]);
                    l %= abs(inp[tmp] - inp[pos]);
                    prev = -1;
                    if (q & 1) {
                        pos = tmp;
                        dir = -1;
                    }
                } else {
                    l -= abs(inp[tmp] - inp[pos]);
                    prev = pos;
                    pos = tmp;
                    dir = -1;
                }
            } else {
                ll tmp = rev[arr[lower_bound(bend(arr), inp[pos] - l) - arr.begin()]];
                if (tmp == pos && prev == tmp) {
                    break;
                }
                if (prev == tmp) {
                    ll q = l / abs(inp[pos] - inp[tmp]);
                    l %= abs(inp[pos] - inp[tmp]);
                    prev = -1;
                    if (q & 1) {
                        pos = tmp;
                        dir = 1;
                    }
                } else {
                    l -= abs(inp[pos] - inp[tmp]);
                    prev = pos;
                    pos = tmp;
                    dir = 1;
                }
            }
        }
        printf("%I64d\n", pos + 1);
    }

    return 0;
}