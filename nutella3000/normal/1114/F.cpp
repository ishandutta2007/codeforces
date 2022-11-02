#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
//#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const int max_n = (1 << 19);
vector<int> reprimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163 ,167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};
int primes[301];

bitset<62> all_num[301];

int mul[2 * max_n];
int mul_push[2 * max_n];
bitset<62> have[2 * max_n], have_push[2 * max_n];

int mult(int a, int b) {
    return (ll)a * b % mod;
}

int add_que(int a, int b) {
    int res = a + b;
    if (res >= mod) res -= mod;
    if (res < 0) res += mod;
    return res;
}

int binpow(int a, int b) {
    int res = 1;
    for(;b > 0;b >>= 1, a = mult(a, a))
        if (b & 1) res = mult(res, a);
    return res;
}

int inv(int a) {
    return binpow(a, mod - 2);
}

void push_down_(int v, int len) {
    int pr = v / 2;
    have[v] |= have_push[pr];
    have_push[v] |= have_push[pr];

    mul[v] = mult(mul[v], binpow(mul_push[pr], len));
    mul_push[v] = mult(mul_push[v], mul_push[pr]);
}

void push_down(int v, int len) {
    push_down_(v * 2, len >> 1);
    push_down_(v * 2 + 1, len >> 1);
    mul_push[v] = 1;
}

void push_up(int v) {
    have[v] = (have[v * 2] | have[v * 2 + 1]);
    mul[v] = mult(mul[v * 2], mul[v * 2 + 1]);
}

void build(vector<int> a) {
    a.resize(max_n, 1);
    for(int i = 2 * max_n - 1;i >= 1;i--) {
        if (i >= max_n) {
            mul[i] = a[i - max_n];

            have[i] |= all_num[a[i - max_n]];
        }else {
            push_up(i);
        }

        mul_push[i] = 1;
    }
}


void add_que(int tl, int tr, int x, int v = 1, int l = 0, int r = max_n - 1) {
    if (l > tr || r < tl) return;
    if (l >= tl && r <= tr) {
        mul[v] = mult(mul[v], binpow(x, r - l + 1));
        mul_push[v] = mult(mul_push[v], x);

        have[v] |= all_num[x];
        have_push[v] |= all_num[x];

        return;
    }
    push_down(v, r - l + 1);

    int m = ((l + r) >> 1);
    add_que(tl, tr, x, v * 2, l, m);
    add_que(tl, tr, x, v * 2 + 1, m + 1, r);

    push_up(v);
}

int get(int tl, int tr, bitset<62>& a, int v = 1, int l = 0, int r = max_n - 1) {
    if (l > tr || r < tl) return 1;
    if (l >= tl && r <= tr) {
        a |= have[v];
        return mul[v];
    }

    push_down(v, r - l + 1);
    int m = ((l + r) >> 1);
    return mult(get(tl, tr, a, v * 2, l, m), get(tl, tr, a, v * 2 + 1, m + 1, r));
}

void solve() {


    for(int i = 0;i < sz(reprimes);i++) {
        primes[reprimes[i]] = i;
    }

    for(int v = 1;v <= 300;v++) {
        int x = v;
        for(int p = 2;p <= x;p++) {
            if (x % p != 0) continue;

            while(x % p == 0) x /= p;
            all_num[v][primes[p]] = true;
        }
    }

    vector<int> ch(301);

    for(int i = 2;i <= 300;i++) {
        ch[i] = mult(i - 1, inv(i));
    }

    int n, q;
    cin >> n >> q;
    vector<int> temp(n);
    for(int i = 0;i < n;i++)
        cin >> temp[i];

    build(temp);

    for(int i = 0;i < q;i++) {
        string s;
        int l, r, x;
        cin >> s >> l >> r;
        l--; r--;
        if (s == "TOTIENT") {
            bitset<62> a;
            int num = get(l, r, a);
            for(int i = 0;i < 62;i++) {
                if (!a[i]) continue;
                int temp = reprimes[i];
                num = mult(num, ch[temp]);
            }

            cout << num << endl;
        }else {
            cin >> x;
            add_que(l, r, x);
        }
    }
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    solve();
}