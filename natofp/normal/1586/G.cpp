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

bool cmp(pair<pii, int> one, pair<pii, int> two){
    return one.st.nd < two.st.nd;
}

const int nax = 4e5 + 5;
const int mod = 1e9 + 7;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1){
            ret += bit[r];
            if(ret >= mod) ret -= mod;
        }
        return ret;
    }

    int sum(int l, int r) {
        int res = sum(r) - sum(l - 1);
        if(res < 0) res += mod;
        return res;
    }

    void add(int idx, int delta) {
        if(delta < 0) delta += mod;
        delta %= mod;
        for (; idx < n; idx = idx | (idx + 1)){
            bit[idx] += delta;
            if(bit[idx] >= mod) bit[idx] -= mod;
        }
    }
};

int dp[nax];
int n;
pii ith[nax];

vector<pair<pii, int> > a;
set<pii> rightBorder;
set<pii> leftBorder;
set<pii> rstRight;
set<pii> rstLeft;
const int sz = nax + 5;
FenwickTree d(sz);

void eraseBad(int lo, int hi){
    set<int> out;
    auto it = leftBorder.begin();
    while(it != leftBorder.end()){
        int L = (*it).st;
        if(L < lo) out.insert((*it).nd);
        else break;
        it++;
    }
    auto it2 = rightBorder.rbegin();
    while(it2 != rightBorder.rend()){
        int R = (*it2).st;
        if(R > hi) out.insert((*it2).nd);
        else break;
        it2++;
    }

    for(int id : out){
        int L = ith[id].st;
        int R = ith[id].nd;
        d.add(id, -dp[id]-1);
        rightBorder.erase(mp(R, id));
        leftBorder.erase(mp(L, id));
    }

    out.clear();

    it = rstLeft.begin();
    while(it != rstLeft.end()){
        int L = (*it).st;
        if(L < lo) out.insert((*it).nd);
        else break;
        it++;
    }
    it2 = rstRight.rbegin();
    while(it2 != rstRight.rend()){
        int R = (*it2).st;
        if(R > hi) out.insert((*it2).nd);
        else break;
        it2++;
    }

    for(int id : out){
        int L = ith[id].st;
        int R = ith[id].nd;
        d.add(id, -dp[id]-1);
        rstRight.erase(mp(R, id));
        rstLeft.erase(mp(L, id));
    }

}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int x, y; cin >> x >> y;
        a.pb(mp(mp(x, y), i));
        ith[i] = mp(x, y);
    }
    int t; cin >> t;
    set<int> pres;
    while(t--){
        int x; cin >> x;
        rightBorder.insert(mp(a[x - 1].st.nd, x));
        leftBorder.insert(mp(a[x - 1].st.st, x));
        pres.insert(x);
    }
    for(int i=1;i<=n;i++){
        if(pres.count(i) == 0){
            rstRight.insert(mp(a[i - 1].st.nd, i));
            rstLeft.insert(mp(a[i - 1].st.st, i));
        }
    }
    sort(a.begin(), a.end(), cmp); // sort by bi
    FenwickTree tri(sz);
    for(auto cur : a){
        int id = cur.nd;
        int L = cur.st.st;
        dp[id] = tri.sum(L, sz - 1);
        tri.add(L, dp[id] + 1);
    }
    for(int i=1;i<=n;i++){
        d.add(i, dp[i] + 1);
    }

    eraseBad(1, (*rightBorder.rbegin()).st);

    int ans = 0;
    while(rightBorder.size()){
        pii last = (*rightBorder.rbegin());
        int R = last.st;
        int id = last.nd;
        int L = ith[id].st;
        d.add(id, - dp[id] - 1);
        ans += d.sum(0, sz - 1) + 1;
        ans %= mod;
        leftBorder.erase(mp(L, id));
        rightBorder.erase(mp(R, id));
        if(rightBorder.empty()) break;
        eraseBad(L, R);
        if(rightBorder.empty()) break;
        R = (*rightBorder.rbegin()).st;
        eraseBad(L, R);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}