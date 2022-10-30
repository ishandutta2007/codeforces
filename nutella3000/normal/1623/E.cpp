#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e9 + 7, mod = 1e9 + 7;
const int N = 2e5 + 3, log_n = 20;

int n, k;
string s;
int ch[N][2];
int par[N][log_n];

vector<int> ord;
void predfs(int v, int pr = 0) {
    if (!v) return;
    par[v][0] = pr;
    for (int i = 1; i < log_n; ++i)
        par[v][i] = par[par[v][i-1]][i-1];

    predfs(ch[v][0], v);
    ord.pb(v);
    predfs(ch[v][1], v);
}


bool ban[N], good[N];
void push_ban(int v) {
    if (ban[v] || good[v]) return;
    ban[v] = true;
    push_ban(ch[v][0]);
    push_ban(ch[v][1]);
}

void try_push(int st) {
    if (ban[st] || good[st]) return;

    int v = st, dick = 1;
    for (int k = log_n-1; k >= 0; --k) {
        if (!good[par[v][k]]) v = par[v][k], dick += (1<<k);
    }
    if (dick > k) return;
    k -= dick;
    v = st;
    while (!good[v]) {
        good[v] = true;
        v = par[v][0];
    }
}


void run() {
    cin >> n >> k >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> ch[i][0] >> ch[i][1];
    }
    s = '#' + s;
    predfs(1);

    good[0] = true;

    vector<char> lst(n);
    lst[n-1] = 'a';

    for (int i = n - 2; i >= 0; --i) {
        if (s[ord[i]] == s[ord[i+1]]) lst[i] = lst[i+1];
        else lst[i] = s[ord[i+1]];
    }

    for (int i = 0; i < n-1; ++i) {
        if (s[ord[i]] < lst[i]) {
            try_push(ord[i]);
        } else if (s[ord[i]] > lst[i]) {
            push_ban(ord[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << s[ord[i]];
        if (good[ord[i]]) cout << s[ord[i]];
    }
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(5);
    //auto time = clock();
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}