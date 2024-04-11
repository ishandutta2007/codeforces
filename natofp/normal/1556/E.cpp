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

const int nax = 1e5 + 5;
ll a[nax];
ll b[nax];
ll dif[nax];
int n, q;

const int roz = (1 << 18);

ll tree[2][roz][2];

void add(int lo, int hi, int u, int a, int b, ll val, int id){
    if(lo == a && b == hi){
        tree[id][u][0] += val;
        tree[id][u][1] += val;
        return;
    }
    if(b<=a)return;
    int mid = (lo + hi) / 2;
    add(lo,mid,u*2,a,min(b,mid),val,id);
    add(mid,hi,u*2+1,max(a,mid),b,val,id);
    tree[id][u][0] = max(tree[id][u * 2][0], tree[id][u * 2 + 1][0]) + tree[id][u][1];
}

ll ask(int lo, int hi, int u, int a, int b, int id){
    if(lo == a && b == hi){
        return tree[id][u][0];
    }
    if(b <= a) return -1e18;
    int mid = (lo + hi) / 2;
    ll L = ask(lo,mid,u*2,a,min(b,mid),id);
    ll R = ask(mid,hi,u*2+1,max(a,mid),b,id);
    return max(L, R) + tree[id][u][1];
}

ll pref[nax];

struct seg{
    ll maxsum;
    ll minsum;
    ll maxpref;
    ll minpref;
    ll maxsuf;
    ll minsuf;
    ll sum;
};

seg drzewo[roz];

seg merge(seg one, seg two){
    seg res;
    res.sum = one.sum + two.sum;
    res.maxsum = max(one.maxsum, two.maxsum);
    res.maxsum = max(res.maxsum, one.maxsuf + two.maxpref);
    res.minsum = min(one.minsum, two.minsum);
    res.minsum = min(res.minsum, one.minsuf + two.minpref);
    res.maxpref = max(one.maxpref, one.sum + two.maxpref);
    res.minpref = min(one.minpref, one.sum + two.minpref);
    res.maxsuf = max(two.maxsuf, two.sum + one.maxsuf);
    res.minsuf = min(two.minsuf, two.sum + one.minsuf);
    return res;
}

void ini(int pos, ll x){
    seg nowy;
    nowy.sum = x;
    nowy.maxpref = x;
    nowy.maxsuf = x;
    nowy.minpref = x;
    nowy.minsuf = x;
    nowy.maxsum = x;
    nowy.minsum = x;
    drzewo[pos + roz / 2] = nowy;
}

seg nowy;

void bad(int pos){
    drzewo[pos + roz / 2] = nowy;
}

seg pyt(int lo, int hi, int u, int a, int b){
    if(lo == a && b == hi) return drzewo[u];
    if(b<=a) return nowy;
    int mid = (lo+hi)/2;
    auto L = pyt(lo,mid,u*2,a,min(b,mid));
    auto R = pyt(mid,hi,u*2+1,max(a,mid),b);
    return merge(L, R);
}

void solve(){
    nowy.sum = 0;
    nowy.maxpref = -1e18;
    nowy.maxsuf = -1e18;
    nowy.minpref = 1e18;
    nowy.minsuf = 1e18;
    nowy.maxsum = -1e18;
    nowy.minsum = 1e18;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++){
        dif[i] = a[i] - b[i];
    }
    pref[1] = dif[1];
    for(int i=2;i<=n;i++){
        pref[i] = pref[i - 1] + dif[i];
    }
    for(int i=1;i<=n;i++){
        add(0,roz/2,1,i,i+1,pref[i],0);
    }

    for(int i=0;i<roz/2;i++){
        if(i >= 1 && i <= n) ini(i, dif[i]);
        else bad(i);
    }
    for(int i=roz/2-1;i>=1;i--) drzewo[i] = merge(drzewo[i * 2], drzewo[i * 2 + 1]);
    while(q--){
        int l, r; cin >> l >> r;
        ll maxi = ask(0,roz/2,1,l,r+1,0);
        if(maxi > pref[l - 1] || pref[r] - pref[l - 1] != 0){
            cout << -1 << "\n";
        }
        else{
            seg ans = pyt(0,roz/2,1,l,r+1);
            cout << max(ans.maxsum, abs(ans.minsum)) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}