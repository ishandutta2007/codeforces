#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
const int max_n = (1 << 19);

const int mod = 1e9 + 9;
const int sqrt5 = 383008016;

int mul(int a, int b) {
    return a * b % mod;
}

int sum(int a, int b) {
    int res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

int sub(int a, int b) {
    int res = a - b;
    if (res < 0) res += mod;
    return res;
}

int binpow(int a, int b) {
    int res = 1;
    for(;b;b /= 2, a = mul(a, a)) 
        if (b & 1) res = mul(res, a);
    return res;
}

int rev(int num) {
    return binpow(num, mod - 2);
}

struct node {
    int sum, p1, p2, l, r;

    node() {}
    node(int sum, int p1, int p2, int l, int r) : sum(sum), p1(p1), p2(p2), l(l), r(r) {}    
};

const int num1 = mul(1 + sqrt5, rev(2)), num2 = mul(1 - sqrt5 + mod, rev(2));
int pw1[max_n], pw2[max_n], f1[max_n], f2[max_n];
node s[2 * max_n];

void build(vector<int> a) {
    pw1[0] = pw2[0] = rev(sqrt5);
    f1[0] = f2[0] = 1;

    for(int i = 1;i < max_n;i++) {
        pw1[i] = mul(pw1[i - 1], num1);
        pw2[i] = mul(pw2[i - 1], num2);
        f1[i] = sum(f1[i - 1], mul(pw1[i], sqrt5));
        f2[i] = sum(f2[i - 1], mul(pw2[i], sqrt5));
    }

    for(int i = 2 * max_n - 1;i >= 1;i--) {
        if (i >= max_n) {
            int temp = 0;
            if (i - max_n < a.size()) temp = a[i - max_n];
            s[i] = {temp, 0, 0, i - max_n, i - max_n};

        }else s[i] = {s[i * 2].sum + s[i * 2 + 1].sum, 0, 0, s[i * 2].l, s[i * 2 + 1].r};
    }
}

void update(int v, int p1, int p2) {
    int l = s[v].r - s[v].l;

    s[v].sum += p1 * f1[l] - p2 * f2[l];
    s[v].sum = (s[v].sum % mod + mod) % mod;

    //cout << p1 << " " << l << " " << p2 << " " << s[v].sum << endl;

    s[v].p1 = sum(s[v].p1, p1);
    s[v].p2 = sum(s[v].p2, p2);
}

void push(int v) {
    update(v * 2, s[v].p1, s[v].p2);
    int temp = (s[v].r - s[v].l + 1) / 2;
    int t1 = s[v].p1 * pw1[temp] % mod * sqrt5 % mod;
    int t2 = s[v].p2 * pw2[temp] % mod * sqrt5 % mod;
    /*if (v == 1) {
        cout << s[v].p1 << " " << t1 << " " << t2 << endl;
    }*/
    update(v * 2 + 1, t1, t2);
    s[v].p1 = s[v].p2 = 0;
}

void upd(int v, int l, int r) {
    if (s[v].l > r || s[v].r < l) return;
    if (s[v].l >= l && s[v].r <= r) {
        int temp = s[v].l - l + 1;
        update(v, pw1[temp], pw2[temp]);
        return;
    }
    push(v);

    upd(v * 2, l, r);
    upd(v * 2 + 1, l, r);
    s[v].sum = sum(s[v * 2].sum, s[v * 2 + 1].sum);
}

int get(int v, int l, int r) {
    //cout << v << " " << s[v].sum << endl;
    if (s[v].l > r || s[v].r < l) return 0;
    if (s[v].l >= l && s[v].r <= r) return s[v].sum;
    push(v);
    return sum(get(v * 2, l, r), get(v * 2 + 1, l, r));
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> temp(n);
    for(int i = 0;i < n;i++)
        cin >> temp[i];

    build(temp);

    /*for(int i = 1;i <= 7;i++) 
       cout << "i " << s[i].sum << " " << s[i].l << " " << s[i].r << endl;*/


    /*int n1 = (rev(sqrt5) * (binpow(num1, 4) - 1) % mod * rev(num1 - 1) % mod * num1 % mod);
    int n2 = rev(sqrt5) * (binpow(num2, 4) - 1) % mod * rev(num2 - 1) % mod * num2 % mod;

    int q1 = ((num1 - num2) % mod * rev(sqrt5) % mod + mod) % mod;
    int q2 = ((num1 * num1 - num2 * num2) % mod * rev(sqrt5) % mod + mod) % mod;
    int q3 = ((binpow(num1, 3) - binpow(num2, 3)) % mod * rev(sqrt5) % mod + mod) % mod;
    int q4 = ((binpow(num1, 4) - binpow(num2, 4)) % mod * rev(sqrt5) % mod + mod) % mod;

    cout << q1 << " " << q2 << " " << q3 << " " << q4 << endl;

    cout << ((n1 - n2) % mod + mod) % mod << endl;


    int w1 = rev(sqrt5) * num1 % mod;
    int w2 = (binpow(num1, 4) - 1) * rev(num1 - 1) % mod;

    cout << w1 << " " << pw1[1] << endl << w2 << " " << f1[3] << endl;

    cout << n1 << " " << pw1[1] * f1[3] % mod << endl;
    cout << n2 << " " << pw2[1] * f2[3] % mod << endl;

    int tm = pw1[1] * f1[3] - pw2[1] * f2[3];
    tm = tm % mod;
    cout << (tm % mod + mod) % mod << endl;*/


    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--; r--;

        
            /*for(int i = 0;i < 4;i++) 
                cout << get(1, i, i) << " ";
        cout << endl;*/
        

        if (t == 1) upd(1, l, r);
        else cout << (get(1, l, r) % mod + mod) % mod << endl;
    }


}
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}