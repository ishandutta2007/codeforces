#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

const int MAXN = 300005;
const int MAXT = 2e9;

pii par[MAXN]; int sz[MAXN];
int find(int x, int t = MAXT) {
    if(par[x].s <= t && par[x].f != x)
        return find(par[x].f, t);
    return x;
}

void merge(int x, int y, int t) {
    x = find(x); y = find(y);
    if(sz[x] < sz[y]) {
        par[x] = {y, t};
        sz[y] += sz[x];
    } else {
        par[y] = {x, t};
        sz[x] += sz[y];
    }
}

int maxOnPath(int x, int y) {
    pii xstack[20], ystack[20];
    int xsz = 1, ysz = 1;
    xstack[0] = {x, -1};
    ystack[0] = {y, -1};
    while(par[x].f != x) {
        xstack[xsz++] = par[x];
        x = par[x].f;
    }
    while(par[y].f != y) {
        ystack[ysz++] = par[y];
        y = par[y].f;
    }

    while(xsz != -1 && ysz != -1 && xstack[xsz].f == ystack[ysz].f) {
        xsz--;
        ysz--;
    }
    
    int ans = -1;
    ans = max(ans, xstack[xsz+1].s);
    ans = max(ans, ystack[ysz+1].s);
    return ans;
}

struct Node {
    Node* l = nullptr, *r = nullptr;
    int any = -1, ans = -1;
    int lo, hi;
    bool flag = false, allon = false;
    int allonans;

    Node(int ll, int hh) : lo(ll), hi(hh) {
        if(hh != ll+1) {
            int m = (ll+hh)/2;
            l = new Node(ll, m);
            r = new Node(m, hh);
        }
        allonans = -1;
        FOR(i, ll+1, hh)
            allonans = max(allonans, maxOnPath(i, ll));
    }
    void update(int ll, int rr, bool state) {
        if(rr <= lo || ll >= hi) return;
        
        if(flag && allon == state) return;

        if(ll <= lo && rr >= hi) {
            flag = true;
            allon = state;
            if(allon) {
                ans = allonans;
                any = lo;
            }
            else {
                ans = -1;
                any = -1;
            }
        } else {
            if(flag) {
                flag = false;
                l->update(lo, hi, allon);
                r->update(lo, hi, allon);
            }
            l->update(ll,rr,state);
            r->update(ll,rr,state);
            
            ans = max(l->ans, r->ans);
            any = max(l->any, r->any);
            if(l->any != -1 && r->any != -1)
                ans = max(ans, maxOnPath(l->any, r->any));
        }
    }
};

Node* root;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, q; cin >> n >> q;
    F0R(i, n) {
        sz[i] = 1;
        par[i] = {i, MAXT};
    }

    vector<piii> v;
    F0R(i,n-1) {
        int a, b, c; cin >> a >> b >> c;
        v.pb({c,{a-1,b-1}});
    }
    sort(v.begin(), v.end());
    for(auto x : v)
        merge(x.s.f, x.s.s, x.f);

    root = new Node(0, n);

    F0R(i, q) {
        int a; cin >> a;
        if(a == 1 || a == 2) {
            int l, r; cin >> l >> r;
            root->update(l-1,r,a == 1);
        } else {
            int b; cin >> b;
            if(root->any == -1) cout << -1 << '\n';
            else cout << max(root->ans, maxOnPath(root->any, b-1)) << '\n';
        }
    }
}