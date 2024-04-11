#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 3e5 + 5;
int a[nax];
int n;

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<ll> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    FenwickTree A(nax), B(nax);
    vector<ll> ans;
    ll last = 0;
    ll sum = 0;
    for(int i=1;i<=n;i++){
        int value = a[i];
        ll cur = sum;
        bool dbg = (i == 3);
        for(int j=0;j<nax;j+=value){
            int lo = j;
            int hi = min(lo + value - 1, nax - 1);
            cur -= A.sum(lo, hi) * j;
        }
        cur += (ll)value * (i - 1);
        cur -= B.sum(value, nax - 1);
        last += cur;
        ans.pb(last);
        sum += value;
        A.add(value, 1);
        for(int j=value;j<nax;j+=value){
            int lo = j - 1;
            int hi = min(lo + value, nax - 1);
            B.add(lo, -j);
            B.add(hi, j);
        }
    }
    for(auto x : ans) cout << x << " ";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}