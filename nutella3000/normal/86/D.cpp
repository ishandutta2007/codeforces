#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
const int max_n = 2e5 + 3;

struct que {
    int l, r, id;
    que() {}

    que(int l, int r, int id) : l(l), r(r), id(id) {}
};

int n;
int a[max_n];
vector<que> q;
vector<ll> res;
ll sum = 0;
int b[(int) 1e6 + 1];
int l = 0, r = -1;

void add(int num) {
    sum += (ll)(2 * b[num] + 1) * num;
    b[num]++;
}

void rem(int num) {
    b[num]--;
    sum -= (ll)(2 * b[num] + 1) * num;
}

int bl;

void solve() {
    int t;
    cin >> n >> t;
    //scanf("%d%d", &n, &t);
    bl = sqrt(n);

    q.resize(t);
    res.resize(t);

    for(int i = 0;i < n;i++)
        cin >> a[i];

    for(int i = 0;i < t;i++) {
        int ql, qr;
        cin >> ql >> qr;
        ql--, qr--;
        q[i] = {ql, qr, i};
    }

    sort(all(q), [](que a, que b) {return mp(a.l / bl, a.r) < mp(b.l / bl, b.r);});


    for(que v : q) {
        while(l < v.l) rem(a[l++]);
        while(l > v.l) add(a[--l]);
        while(r < v.r) add(a[++r]);
        while(r > v.r) rem(a[r--]);

        res[v.id] = sum;
    }

    for(ll i : res) 
        cout << i << endl;
}




signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}