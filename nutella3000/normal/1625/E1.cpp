#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>

mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e18 + 7;
const int N = (1 << 19);

int n, q;
string s;
int h[N], type[N], R[N], T = 1;
set<int> sex[N];
ll sum[2*N];

void del(int v) {
    int id = R[type[v]];
    for (id += N; id; id >>= 1)
        sum[id] -= size(sex[type[v]])-1;
    sex[type[v]].erase(v);
}

map<int, int> val[2*N];

void run() {
    cin >> n >> q >> s;
    deque<int> ids{0};
    sex[0].emplace(0);

    for (int i = 0; i < n; ++i) {
        h[i+1] = h[i] + (s[i] == '(' ? 1 : -1);
        while (size(ids) && h[ids.back()] > h[i+1])
            ids.pop_back();
        if (ids.empty() || h[ids.back()] != h[i+1]) {
            type[i+1] = T++;
        }
        else {
            type[i+1] = type[ids.back()];
        }
        sex[type[i+1]].emplace(i+1);
        ids.pb(i+1);
    }

    for (int i = 0; i <= n; ++i)
        val[i+N][h[i]] = 1;
    for (int i = N-1; i; --i) {
        for (auto j : val[2*i])
            val[i][j.fi] += j.se;
        for (auto j : val[2*i+1])
            val[i][j.fi] += j.se;
    }


    for (int it = 0; it < T; ++it) {
        int id = *sex[it].rbegin();
        R[it] = id;
        for (id += N; id; id >>= 1)
            sum[id] += (ll)size(sex[it]) * (size(sex[it])-1)/2;
    }
    while (q--) {
        int t, l, r; cin >> t >> l >> r; --l, --r;
        if (t == 1) {
            del(l), del(r);
        } else {
            ll res = 0;
            for (int tl = l+N+1, tr=r+N+1; tl < tr; tl >>= 1, tr >>= 1) {
                if (tl & 1) res += sum[tl++];
                if (tr & 1) res += sum[--tr];
            }
            int d = 1;
            for (int tl = l+N, tr = r+N+1; tl < tr; tl >>= 1, tr >>= 1) {
                if (tl & 1) d += val[tl++][h[l]];
                if (tr & 1) d += val[--tr][h[l]];
            }

            cout << res + (ll)d*(d-1)/2 << endl;
        }
    }
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}