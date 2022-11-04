#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;

template <typename T, T MOD>
class ModInt;

template <typename T, T MOD>
ModInt<T, MOD> lgpow(ModInt<T, MOD> a, ll b) {
    assert(b >= 0);

    ModInt<T, MOD> ans(1);
    while(b > 0) {
        if(b & 1) ans *= a;
        b >>= 1, a *= a;
    }
    return ans;
}

template <typename T, T MOD>
ModInt<T, MOD> inv(ModInt<T, MOD> a) {
    return lgpow(a, MOD - 2);
}


template <typename T, T MOD>
class ModInt {

protected:

    T val;

    inline T mod(ll x) const {
        if(llabs(x) >= MOD) {
            x %= MOD;
        }
        return (x < 0 ? MOD : 0) + x;
    }

public:

    explicit ModInt(int _val = 0) : val(mod(_val)) {}
    ModInt(const ModInt &y) : val(y.val) {}

    ModInt operator +(const ModInt &y) const {
        return ModInt(mod(val + y.val));
    }
    ModInt operator +(const int &y) const {
        return *this + ModInt(y);
    }
    ModInt operator -(const ModInt &y) const {
        return ModInt(mod(val - y.val));
    }
    ModInt operator -(const int &y) const {
        return *this - ModInt(y);
    }
    ModInt operator *(const ModInt &y) const {
        return ModInt(mod(1LL * val * y.val));
    }
    ModInt operator *(const int &y) const {
        return *this * ModInt(y);
    }
    ModInt operator /(const ModInt &y) const {
        return ModInt(mod(1LL * val * inv(y).val));
    }
    ModInt operator /(const int &y) const {
        return *this / ModInt(y);
    }
    ModInt& operator =(const ModInt &y) {
        val = y.val;
        return *this;
    }
    ModInt& operator =(const int &y) {
        val = mod(y);
        return *this;
    }

    bool operator ==(const ModInt &y) const {
        return val == y.val;
    }
    bool operator ==(const T &y) const {
        return val == y;
    }
    bool operator !=(const ModInt &y) const {
        return val != y.val;
    }
    bool operator !=(const T &y) const {
        return val != y;
    }
    bool operator <(const ModInt &y) const {
        return val < y.val;
    }
    bool operator <(const T &y) const {
        return val < y;
    }
    bool operator <=(const ModInt &y) const {
        return val <= y.val;
    }
    bool operator <=(const T &y) const {
        return val <= y;
    }
    bool operator >(const ModInt &y) const {
        return val > y.val;
    }
    bool operator >(const T &y) const {
        return val > y;
    }
    bool operator >=(const ModInt &y) const {
        return val >= y.val;
    }
    bool operator >=(const T &y) const {
        return val >= y;
    }

    ModInt& operator +=(const ModInt &y) {
        val = mod(val + y.val);
        return *this;
    }
    ModInt& operator +=(const T &y) {
        val = mod(val + y);
        return *this;
    }
    ModInt& operator -=(const ModInt &y) {
        val = mod(val - y.val);
        return *this;
    }
    ModInt& operator -=(const T &y) {
        val = mod(val - y);
        return *this;
    }
    ModInt& operator *=(const ModInt &y) {
        val = mod(1LL * val * y.val);
        return *this;
    }
    ModInt& operator *=(const T &y) {
        val = mod(1LL * val * y);
        return *this;
    }
    ModInt& operator /=(const ModInt &y) {
        val = mod(1LL * val * inv(y.val));
        return *this;
    }
    ModInt& operator /=(const T &y) {
        val = mod(1LL * val * inv(y));
        return *this;
    }

    ModInt& operator ++() {
        val = mod(val + 1);
        return *this;
    }
    ModInt operator ++(int) {
        ModInt ans(val);
        val = mod(val + 1);
        return ans;
    }
    ModInt& operator --() {
        val = mod(val - 1);
        return *this;
    }
    ModInt operator --(int) {
        ModInt ans(val);
        val = mod(val - 1);
        return ans;
    }

    operator int() const {
        return (int)val;
    }
    operator ll() const {
        return (ll)val;
    }


    friend std::ostream& operator <<(std::ostream &stream, const ModInt &x) {
        return stream << x.val;
    }
    friend std::istream& operator >>(std::istream &stream, ModInt &x) {
        int cur;
        stream >> cur;
        x = ModInt<T, MOD>(cur);
        return stream;
    }

    friend ModInt operator +(int x, const ModInt &y) {
        return ModInt(x) + y;
    }
    friend ModInt operator -(int x, const ModInt &y) {
        return ModInt(x) - y;
    }
    friend ModInt operator *(int x, const ModInt &y) {
        return ModInt(x) * y;
    }
    friend ModInt operator /(int x, const ModInt &y) {
        return ModInt(x) / y;
    }
    friend ModInt operator +=(int x, const ModInt &y) {
        return ModInt(x) + y;
    }
    friend ModInt operator -=(int x, const ModInt &y) {
        return ModInt(x) - y;
    }
    friend ModInt operator *=(int x, const ModInt &y) {
        return ModInt(x) * y;
    }
    friend ModInt operator /=(int x, const ModInt &y) {
        return ModInt(x) / y;
    }

};


const int MOD = (int) 998244353;

using Mint = ModInt<int, MOD>;

vector < vector <Mint> > pinv;

struct Node {
    Mint dp[2][2];
    Node() {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                dp[i][j] = 0;
            }
        }
    }
    void operator =(const Node &other) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                dp[i][j] = other.dp[i][j];
            }
        }
    }
};

class SegTree {

public:

    vector <Node> aint;
    int n;

    inline void init(int _n) {
        n = _n;
        int sz = 1;
        while(sz < 2 * n) {
            sz *= 2;
        }
        aint.resize(sz + 1);
    }

    inline void update(int l, int r, Node &cur) { // l == r ???
        update(1, 1, n, l, r, cur);
    }

    inline void query(int pos, Node &cur) {
        query(1, 1, n, pos, cur);
    }

private:

    inline Node combine(Node x, Node y, int l, int r) {
        int mid = (l + r) / 2;
        Node ans;

        for(int a = 0; a < 2; a++) {
            for(int b = 0; b < 2; b++) {
                for(int c = 0; c < 2; c++) {
                    ans.dp[a][c] += x.dp[a][b] * y.dp[b][c] * pinv[mid + 1][b];
                }
            }
        }
        return ans;
    }

    void update(int nod, int left, int right, int l, int r, Node &cur) {
        if(l <= left && right <= r) {
            aint[nod] = cur;
            return ;
        }
        int mid = (left + right) / 2;

        if(l <= mid) update(2 * nod, left, mid, l, r, cur);
        if(mid < r) update(2 * nod + 1, mid + 1, right, l, r, cur);

        aint[nod] = combine(aint[2 * nod], aint[2 * nod + 1], left, right);
    }

    void query(int nod, int left, int right, int pos, Node &cur) {
        if(left == right) {
            cur = aint[nod];
            return ;
        }
        int mid = (left + right) / 2;

        if(pos <= mid) query(2 * nod, left, mid, pos, cur);
        else query(2 * nod + 1, mid + 1, right, pos, cur);
    }
};


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> x(n + 1), v(n + 1);
    vector <Mint> p(n + 1);
    pinv.resize(n + 1, vector <Mint>(2));

    for(i = 1; i <= n; i++) {
        cin >> x[i] >> v[i] >> p[i];
        p[i] *= inv(Mint(100));

        pinv[i][0] = inv(1 - p[i]);
        pinv[i][1] = inv(p[i]);
    }

    struct Event {
        int tx, ty, id;
        bool a, b;
        bool operator <(const Event &other) const {
            return 1LL * tx * other.ty < 1LL * other.tx * ty;
        }
    };

    vector <Event> evs;
    SegTree st; st.init(n - 1);

    auto get = [&](Node &cur, int i) -> void {
        cur.dp[0][0] = (1 - p[i]) * (1 - p[i + 1]);
        cur.dp[1][1] = p[i] * p[i + 1];
        cur.dp[1][0] = p[i] * (1 - p[i + 1]);
        cur.dp[0][1] = (1 - p[i]) * p[i + 1];

        if(v[i + 1] > v[i]) {
            evs.push_back({x[i + 1] - x[i], v[i + 1] - v[i], i, 0, 0});
        }

        if(v[i] > v[i + 1]) {
            evs.push_back({x[i + 1] - x[i], v[i] - v[i + 1], i, 1, 1});
        }

        evs.push_back({x[i + 1] - x[i], v[i] + v[i + 1], i, 1, 0});
    };

    for(i = 1; i < n; i++) {
        Node cur;
        get(cur, i);
        st.update(i, i, cur);
    }

    sort(evs.begin(), evs.end());

    vector <Mint> prob(1, Mint(1));
    for(auto &it : evs) {
        Node cur;
        st.query(it.id, cur);
        cur.dp[it.a][it.b] = 0;

        st.update(it.id, it.id, cur);

        prob.push_back(Mint(0));
        for(int a = 0; a < 2; a++) {
            for(int b = 0; b < 2; b++) {
                prob.back() += st.aint[1].dp[a][b];
            }
        }
    }

    Mint ans(0);
    for(i = 0; i + 1 < prob.size(); i++) {
        ans += (prob[i] - prob[i + 1]) * Mint(evs[i].tx) * inv(Mint(evs[i].ty));
    }

    cout << ans;

    return 0;
}