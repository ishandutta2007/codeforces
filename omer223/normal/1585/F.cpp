#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define chkmin(a, b) (a = ((a > b) ? b : a))
#define chkmax(a, b) (a = ((a < b) ? b : a))

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <memory>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, int> pdi;
typedef ll T;

const ll mod = 998244353;

int add(int a, int b) {
    return (a + b) % mod;
}

int mult(int a, int b) {
    return ((ll)a * (ll)b) % mod;
}

struct M {
    using T = pii;//val, size
    static T id(int len) { return { 0,len }; }
    static T op(T a, T b) {
        return { add(a.ff,b.ff),a.ss + b.ss };
    }
};

struct O {
    using T = pii; //plus, set
    static T id() { return { 0LL,-1LL }; }
    static T op(T a, T b) {
        if (b.ss != -1)return b;
        return { add(a.ff,b.ff),a.ss };
    }
};


M::T act(M::T a, O::T b) {
    ll initval;
    if (b.ss == -1)initval = a.ff;
    else initval = mult(b.ss, a.ss);
    return { add(initval, mult(b.ff, a.ss)) ,a.ss };
}



template <typename M, typename O, typename M::T(*act)(typename M::T, typename O::T)>
class DynamicLazySegmentTree {
    using T = typename M::T;
    using E = typename O::T;

public:
    DynamicLazySegmentTree() = default;
    explicit DynamicLazySegmentTree(long long n) {
        size = 1;
        while (size < n) size <<= 1;
        root = std::make_unique<Node>(size);
    }

    T operator[](long long k) const {
        return fold(k, k + 1);
    }

    void update(long long l, long long r, const E& x) const { update(l, r, x, root, 0, size); }

    T fold(long long l, long long r) const { return fold(l, r, root, 0, size); }

    void print(int until) {
        for (int i = 1; i <= until; i++)cout << fold(i, i + 1).ff << ' ';
        cout << '\n';
    }

private:
    struct Node;
    using node_ptr = std::unique_ptr<Node>;

    struct Node {
        T val;
        E lazy;
        std::unique_ptr<Node> left, right;
        Node() : val(M::id(0)), lazy(O::id()), left(nullptr), right(nullptr) {}
        Node(int len): val(M::id(len)), lazy(O::id()), left(nullptr), right(nullptr) {}
    };

    node_ptr root;
    long long size;

    void push(const node_ptr& n) const {
        ll l = 0, r = n->val.ss, mid = (l + r) / 2;
        if (n->lazy == O::id()) return;
        if (!n->left) n->left = std::make_unique<Node>(mid-l);
        n->left->lazy = O::op(n->left->lazy, n->lazy);
        if (!n->right) n->right = std::make_unique<Node>(r-mid);
        n->right->lazy = O::op(n->right->lazy, n->lazy);
        n->val = act(n->val, n->lazy);
        n->lazy = O::id();
    }

    void update(long long a, long long b, const E& x, const node_ptr& n, long long l, long long r) const {
        push(n);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            n->lazy = O::op(n->lazy, x);
            push(n);
            return;
        }
        long long m = (l + r) / 2;
        if (!n->left) n->left = std::make_unique<Node>(m-l);
        update(a, b, x, n->left, l, m);
        if (!n->right) n->right = std::make_unique<Node>(r-m);
        update(a, b, x, n->right, m, r);
        n->val = M::op(n->left->val, n->right->val);
    }

    T fold(long long a, long long b, const node_ptr& n, long long l, long long r) const {
        push(n);
        if (r <= a || b <= l) return M::id(r-l);
        if (a <= l && r <= b) return n->val;
        long long m = (l + r) / 2;
        T vl = n->left ? fold(a, b, n->left, l, m) : M::id(m-l);
        T vr = n->right ? fold(a, b, n->right, m, r) : M::id(r-m);
        return M::op(vl, vr);
    }

    
};



int main() {
    fast;
    int n;
    cin >> n;
    if (n == 1) {
        int a;
        cin >> a;
        cout << a%mod << '\n';
        return 0;
    }
    const int maxval = 1e9+5;
    DynamicLazySegmentTree<M, O, act> tre(maxval);
    ll prv = mod-1;
    foru(i, 0, n) {
        int a;
        cin >> a;
        tre.update(1, a + 1, { mod - prv,-1 });
        tre.update(a + 1, maxval + 1, { 0,0 });
        prv = tre.fold(1, maxval + 1).ff;
    }
    prv %= mod;
    if (n%2==0)cout << (mod-prv)%mod << '\n';
    else cout << prv << '\n';
    return 0;
}