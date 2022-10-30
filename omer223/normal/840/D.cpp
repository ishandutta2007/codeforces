#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

template <typename T>
struct wavelet_tree {
    struct node {
        T lo, hi;
        node* left_child, * right_child;
        std::vector<int> b;
        using iter = typename std::vector<T>::iterator;

        // numbers are in range [x, y]
        // array indices are [from, to)
        node(iter from, iter to, T x, T y) {
            lo = x, hi = y;
            left_child = nullptr;
            right_child = nullptr;
            if (lo == hi || from >= to)
                return;
            T mid = lo + (hi - lo) / 2;
            auto f = [mid](T e) { return e <= mid; };
            b.reserve(to - from + 1);
            b.push_back(0);
            for (auto it = from; it != to; it++)
                b.push_back(b.back() + f(*it));
            auto pivot = std::stable_partition(from, to, f);
            left_child = new node(from, pivot, lo, mid);
            right_child = new node(pivot, to, mid + 1, hi);
        }

        // kth smallest element in [l, r]
        T kth_smallest(int l, int r, int k) {
            if (l > r)
                return 0;
            if (lo == hi)
                return lo;
            // how many in the first (l-1) numbers that go left
            int lb = b[l - 1];
            // how many in first (r) numbers that go left
            int rb = b[r];
            int inLeft = rb - lb;
            if (k <= inLeft)
                return this->left_child->kth_smallest(lb + 1, rb, k);
            return this->right_child->kth_smallest(l - lb, r - rb, k - inLeft);
        }

        // count of numbers in [l, r] less than or equal to k
        int count_less_equal(int l, int r, T k) {
            if (l > r or k < lo)
                return 0;
            if (hi <= k)
                return r - l + 1;
            int lb = b[l - 1], rb = b[r];
            return this->left_child->count_less_equal(lb + 1, rb, k) +
                this->right_child->count_less_equal(l - lb, r - rb, k);
        }

        // count of numbers in [l, r] equal to k
        int count_equal(int l, int r, T k) {
            if (l > r || k < lo || k > hi)
                return 0;
            if (lo == hi)
                return r - l + 1;
            int lb = b[l - 1], rb = b[r], mid = lo + (hi - lo) / 2;
            if (k <= mid)
                return this->left_child->count_equal(lb + 1, rb, k);
            return this->right_child->count_equal(l - lb, r - rb, k);
        }
        ~node() {
            delete left_child;
            delete right_child;
        }
    };
    vector<T> a;
    node* nd;
    wavelet_tree(vector<T>& A) {
        this->a = A;
        auto minmax_iterators =
            minmax_element(std::begin(this->a), std::end(this->a));
        this->nd =
            new node(std::begin(this->a), std::end(this->a),
                *(minmax_iterators.first), *(minmax_iterators.second));
    }
    T kth_smallest(int l, int r, int k) {
        ++l, ++r;
        return nd->kth_smallest(l, r, k);
    }
    int count_less_equal(int l, int r, T k) {
        ++l, ++r;
        return nd->count_less_equal(l, r, k);
    }
    int count_equal(int l, int r, T k) {
        ++l, ++r;
        return nd->count_equal(l, r, k);
    }
    ~wavelet_tree() { delete this->nd; }
};

int main() {
    fast;
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    foru(i, 0, n)cin >> a[i];
    wavelet_tree wv(a);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        int len = r - l + 1;
        int bst = 1e9 + 5;
        foru(i, 0, k) {
            int cand = wv.kth_smallest(l, r, ((i + 1) * len) / k);
            int cnt = wv.count_equal(l, r, cand);
            if (k * cnt > len)bst = min(bst, cand);
        }
        if (bst > 1e9)cout << -1 << '\n';
        else cout << bst << '\n';
    }
	return 0;
}