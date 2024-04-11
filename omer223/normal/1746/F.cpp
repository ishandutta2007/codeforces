#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const int sz=  20;
ll h(ll i) {
    for(int j = 0; j < 5; j++) i = (i * i) % mod;
    return i;
}
struct st {
    int nums[sz];
    st(int n) {
        for(int i = 0; i < sz; i++) nums[i] = (n >> i) & 1;
    }
    void pe(st & oth) {
        for(int i = 0; i < sz; i++) nums[i] += oth.nums[i];
    }
    static st p(st & a, st & b) {
        st r(0);
        for(int i = 0; i < sz; i++) r.nums[i] = a.nums[i] + b.nums[i];
        return r;
    }
};
struct segtree{
    vector<st> seg;
    int N;
    segtree(int M){
        N = M;
        seg.resize(2*N, st(h(0)));
    }
    void update(int k, st x){
        k += N; 
        seg[k] = x;
        while(k /= 2){
            seg[k] = st::p(seg[2*k], seg[2*k+1]);
        }
    }
    st query(int l, int r){
        l += N; r += N;
        st ret(0);
        while(l <= r){
            if(l&1){
                ret.pe(seg[l]);
                ++l;
            }
            if(!(r&1)){
                ret.pe(seg[r]);
                --r;
            }
            l /= 2; r /= 2;
        }
        return ret;
    }
};
void solve() {
    int n, q; cin >> n >> q;
    segtree t(n + 2);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        t.update(i, st(h(x)));
    }
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int i, x; cin >> i >> x;
            t.update(i - 1, st(h(x)));
        } else {
            int l, r, k; cin >> l >> r >> k;
            st res = t.query(l - 1, r - 1);
            bool cond = true;
            for(int i = 0; i < sz; i++) {
                if(res.nums[i] % k) {
                    cout << "NO" << '\n';
                    cond = false;
                    break;
                }
            }
            if(cond)
            cout << "YES" << '\n';
        }
    }
}

main() {
    int t = 1;
    while(t--)
        solve();
}