#ifdef ONPC
# define _GLIBCXX_DEBUG
#define deb(a) cerr << "nu smotri pidor " << #a << " = " << a << endl;
#else
#define deb(a)
#endif
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
 
 
using namespace std;
 
 
typedef int ll;
typedef long double ld;
ll MOD = 1e9 + 7;
 
const int N = 410000;
vector<ll> tr[N];
class SegmentTreeFC {
 
    int sz;
    vector< vector<int> > t, tl, tr;
 
    void build(int v, int vl, int vr, const vector<int> &a) {
        if (vl == vr) {
            t[v].push_back(a[vl]);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
 
        int l = 2 * v + 1, r = 2 * v + 2;
        int ls = t[l].size(), rs = t[r].size(), ts = ls + rs;
        t[v].resize(ts);
        tl[v].resize(ts + 1);
        tr[v].resize(ts + 1);
        tl[v][ts] = ls;
        tr[v][ts] = rs;
        for (int i = ts - 1, li = ls - 1, ri = rs - 1; i >= 0; i--) {
            if (li < 0)
                t[v][i] = t[r][ri--];
            else if (ri < 0)
                t[v][i] = t[l][li--];
            else if (t[l][li] > t[r][ri])
                t[v][i] = t[l][li--];
            else
                t[v][i] = t[r][ri--];
            tl[v][i] = (li >= 0 && t[l][li] >= t[v][i] ? li : li + 1);
            tr[v][i] = (ri >= 0 && t[r][ri] >= t[v][i] ? ri : ri + 1);
        }
    }
 
    int query(int v, int vl, int vr, int l, int r, int k, int ub) const {
        if (ub == -1)
            ub = upper_bound(t[v].begin(), t[v].end(), k) - t[v].begin();
        if (r < vl || vr < l)
            return 0;
        if (l <= vl && vr <= r)
            return vr - vl + 1 - ub;
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r, k, tl[v][ub]);
        int qr = query(2 * v + 2, vm + 1, vr, l, r, k, tr[v][ub]);
        return ql + qr;
    }
 
public:
 
    SegmentTreeFC(const vector<int> &a) {
        sz = a.size();
        t.resize(4 * sz);
        tl.resize(4 * sz);
        tr.resize(4 * sz);
        build(0, 0, sz - 1, a);
    }
 
    int query(int l, int r, int k) const {
        return query(0, 0, sz - 1, l, r, k, -1);
    }
 
};
 
 
 
 
 
 
void inc(ll i, ll x){
    for (;i < N; i = ((i + 1) | i)){
        tr[i].push_back(x);
     //   sort(tr[i].begin(), tr[i].end());
    }
}
ll sm(ll i, ll r, ll l){
    ll ans = 0;
    for (; i > -1; i = ((i + 1) & i) - 1){
        ans += lower_bound(tr[i].begin(), tr[i].end(), r) - lower_bound(tr[i].begin(), tr[i].end(), l);
    }
    return ans;
}
 
ll kol(ll a, ll b, ll l, ll r){ // [a; b] [l; r]
    return sm(b, r + 1, l) - sm(a - 1, r + 1, l);
}
 
 
int p[N], cnt[N], c[N];
int pn[N], cn[N];
const int alphabet = 256; //  , <= maxlen
 
ll check(string a, string b){
    //cout << a << " " << b << endl;
 
    if (a < b){
        //cout << "mem2" << endl;
        return 2;
    }
    if (a == b){
        //cout << "mem1" << endl;
        return 1;
    }
 
    //cout << "mem0" << endl;
    return 0;
}
char tt[N];
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout << fixed << setprecision(20);
    ll n, m, q;
    clock_t tm;
    tm = clock();
    scanf("%d%d",&m,&q);
    string s;
    vector<string> t(m);
    vector<ll> nac(m + 1);
    for (int i = 0; i < m; i++){
        scanf("%s",tt);
        t[i] = string(tt);
        nac[i] = s.size();
        s += t[i];
        s += (char)(0);
    }
    nac[m] = s.size() - 1;
    n = s.size();
    memset (cnt, 0, alphabet * sizeof(int));
    for (int i=0; i<n; ++i)
        ++cnt[s[i]];
    for (int i=1; i<alphabet; ++i)
        cnt[i] += cnt[i-1];
    for (int i=0; i<n; ++i)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i=1; i<n; ++i) {
        if (s[p[i]] != s[p[i-1]])  ++classes;
        c[p[i]] = classes-1;
    }
    for (int h=0; (1<<h)<n; ++h) {
        for (int i=0; i<n; ++i) {
            pn[i] = p[i] - (1<<h);
            if (pn[i] < 0)  pn[i] += n;
        }
        memset (cnt, 0, classes * sizeof(int));
        for (int i=0; i<n; ++i)
            ++cnt[c[pn[i]]];
        for (int i=1; i<classes; ++i)
            cnt[i] += cnt[i-1];
        for (int i=n-1; i>=0; --i)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i=1; i<n; ++i) {
            int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
            if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2])
                ++classes;
            cn[p[i]] = classes-1;
        }
        memcpy (c, cn, n * sizeof(int));
    }
   /// cout << "emme";
    vector<ll> pp;
    for (int i = 0; i < n; i++)
        pp.push_back(p[i]);
    SegmentTreeFC st(pp);
    for (int i = 0; i < N; i++){
        sort(tr[i].begin(), tr[i].end());
    }
    ///cout << endl;
    vector<pair<ll, ll> > zp(m);
    for (int i = 0; i < m; i++){
        ll L = 0, R = n;
        while (R - L > 1){
            ll mid = (R + L) / 2;
            string s2 = "";
            for (int j = p[mid]; j < min(n, p[mid] + (ll)t[i].size()); j++){
                s2 += s[j];
            }
            if (check(s2, t[i]) >= 1){
                L = mid;
            }
            else{
                R = mid;
            }
        }
        zp[i].second = L;
        L = 0, R = n;
        while (R - L > 1){
            ll mid = (R + L) / 2;
            string s2 = "";
            for (int j = p[mid]; j < min(n, p[mid] + (ll)t[i].size()); j++){
                s2 += s[j];
            }
            if (check(s2, t[i]) > 1){
                L = mid;
            }
            else{
                R = mid;
            }
        }
        zp[i].first = L + 1;
    }
    for (int i = 0; i < q; i++){
        ll l, r, k;
        scanf("%d%d%d",&l,&r,&k);
        l--, k--;
        l = nac[l];
        r = nac[r] - 1;
        cout << st.query(zp[k].first, zp[k].second, l - 1) - st.query(zp[k].first, zp[k].second, r) << '\n';
    }
 
#ifdef ONPC
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
//egor lox