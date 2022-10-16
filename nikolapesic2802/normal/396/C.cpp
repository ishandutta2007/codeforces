#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define dec(x, y) fixed << setprecision((y)) << (x)
#define xx first
#define yy second
#define srt(v) sort((v).begin(), (v).end())
#define srtr(v) sort((v).rbegin(), (v).rend())
#define pb push_back
#define popb pop_back
#define sz(a) (int)(a).size()
#define len(a) (int)(a).length()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod=(ll)1e9+7LL;

struct drvo {
    ll vr, lazy;
    drvo(ll _v=0LL, ll _l=0LL) {
        vr=_v;
        lazy=_l;
    }
} st1[1200010], st2[1200010];

int n, q;
ll dub[300010];
vector<int> decca[300010];
pair<int, int> oddo[300010];
int Time;
inline void moduj(ll &sta) {
    sta%=mod;
    if(sta<0LL) sta+=mod;
}
void dfs(int node, int dd) {
    oddo[node].xx=++Time;
    dub[node]=dd;
    for(auto ch:decca[node]) {
        dfs(ch, dd+1);
    }
    oddo[node].yy=Time;
}
void prop1(int node, int tl, int tr) {
    st1[node].vr+=(ll)(tr-tl+1)*st1[node].lazy;
    moduj(st1[node].vr);
    if(tl!=tr) {
        st1[2*node].lazy+=st1[node].lazy;
        moduj(st1[2*node].lazy);
        st1[2*node+1].lazy+=st1[node].lazy;
        moduj(st1[2*node+1].lazy);
    }
    st1[node].lazy=0LL;
}
void upd1(int node, int tl, int tr, int gl, int gr, ll val) {
    prop1(node, tl, tr);
    if(tl>=gl && tr<=gr) {
        st1[node].lazy+=val;
        moduj(st1[node].lazy);
        return;
    }
    int mid=(tl+tr)/2;
    if(mid>=gl) upd1(2*node, tl, mid, gl, gr, val);
    if(mid+1<=gr) upd1(2*node+1, mid+1, tr, gl, gr, val);
    prop1(2*node, tl, mid);
    prop1(2*node+1, mid+1, tr);
    st1[node].vr=st1[2*node].vr+st1[2*node+1].vr;
    moduj(st1[node].vr);
}
ll qr1(int node, int tl, int tr, int poz) {
    prop1(node, tl, tr);
    if(tl==tr) return st1[node].vr;
    int mid=(tl+tr)/2;
    if(mid>=poz) return qr1(2*node, tl, mid, poz);
    return qr1(2*node+1, mid+1, tr, poz);
}
void prop2(int node, int tl, int tr) {
    st2[node].vr+=(ll)(tr-tl+1)*st2[node].lazy;
    moduj(st2[node].vr);
    if(tl!=tr) {
        st2[2*node].lazy+=st2[node].lazy;
        moduj(st2[2*node].lazy);
        st2[2*node+1].lazy+=st2[node].lazy;
        moduj(st2[2*node+1].lazy);
    }
    st2[node].lazy=0LL;
}
void upd2(int node, int tl, int tr, int gl, int gr, ll val) {
    prop2(node, tl, tr);
    if(tl>=gl && tr<=gr) {
        st2[node].lazy+=val;
        moduj(st2[node].lazy);
        return;
    }
    int mid=(tl+tr)/2;
    if(mid>=gl) upd2(2*node, tl, mid, gl, gr, val);
    if(mid+1<=gr) upd2(2*node+1, mid+1, tr, gl, gr, val);
    prop2(2*node, tl, mid);
    prop2(2*node+1, mid+1, tr);
    st2[node].vr=st2[2*node].vr+st2[2*node+1].vr;
    moduj(st2[node].vr);
}
ll qr2(int node, int tl, int tr, int poz) {
    prop2(node, tl, tr);
    if(tl==tr) return st2[node].vr;
    int mid=(tl+tr)/2;
    if(mid>=poz) return qr2(2*node, tl, mid, poz);
    return qr2(2*node+1, mid+1, tr, poz);
}
int main() {
    ios;
    cin >> n;
    for(int i=2; i<=n; ++i) {
        int x; cin >> x;
        decca[x].pb(i);
    }
    dfs(1, 1);
    cin >> q;
    while(q--) {
        int tip, v;
        cin >> tip >> v;
        if(tip==1) {
            ll x, k;
            cin >> x >> k;
            upd1(1, 1, n, oddo[v].xx, oddo[v].yy, x + dub[v]*k);
            upd2(1, 1, n, oddo[v].xx, oddo[v].yy, -k);
        }
        else {
            cout << ((qr1(1, 1, n, oddo[v].xx)+((dub[v]*qr2(1, 1, n, oddo[v].xx))%mod+mod)%mod)%mod+mod)%mod << "\n";
        }
    }
    return 0;
}