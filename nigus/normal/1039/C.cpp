#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod2 = 998244353;

ll n,m,k,q;


vl A;
vl B;
vl XOR;

vl X;
ll base = 127842313442;
unordered_set<ll> xors;
vl xorlist;

ll deg[1100001] = {0};
ll pek[1100001] = {0};

ll TWOS[500001] = {0};

unordered_map<ll,ll> M;
unordered_map<ll,ll> M2;
ll n2 = 0;

ll mod(ll x){
    if(x < 0)return (big-mod(-x))%big;
    if(x < big)return x;
    return x%big;
}

ll par(ll i){
    ll i2 = i;
    while(i2 != pek[i2]){
        i2= pek[i2];
    }
    return i2;
}

void merg(ll i, ll j){
    ll i2 = par(i);
    ll j2 = par(j);
    if(i2 != j2){
        if(deg[i2] < deg[j2]){
            swap(i2,j2);
        }
        deg[i2] += deg[j2];
        pek[j2] = i2;
    }
    return;
}

bool comp(ll i, ll j){
    return XOR[i] < XOR[j];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    ll t = 1;
    for(int c1 = 0; c1 < 500001; c1++){
        TWOS[c1] = t;
        t *= 2;
        t = mod(t);
    }

    scanf("%I64d", &n);
    scanf("%I64d", &m);
    scanf("%I64d", &k);
    /*
    n = 500000;
    m = 500000;
    k = 60;
*/
    for(int c1 = 0; c1 < n; c1++){
        scanf("%I64d", &a);
       // a = rand();
        X.push_back(a);
    }

    for(int c1 = 0; c1 < m; c1++){
        scanf("%I64d", &a);
        scanf("%I64d", &b);
        /*
        a = c1+1;
        b = (c1+1)%n+1;
        */
        a--;
        b--;
        XOR.push_back(X[a]^X[b]);
        A.push_back(a);
        B.push_back(b);

        ll x = (X[a]^X[b]);
        if(xors.find(x) == xors.end()){
            xors.insert(x);
            xorlist.push_back(x);
            M[x] = n;
        }

       // pll newp = {a,x};
        ll newp = x*base+a;
        if(M2.find(newp) == M2.end()){
            M2[newp] = n2;
            n2++;
        }

      //  newp = {b,x};
        newp = x*base+b;
        if(M2.find(newp) == M2.end()){
            M2[newp] = n2;
            n2++;
        }
    }

    for(int c1 = 0; c1 < n2; c1++){
        pek[c1] = c1;
        deg[c1] = 1;
    }
/*
    for(int c1 = 0; c1 < n; c1++){
        sort(all(CI[c1]),comp);
        ll prev = -1;
        for(int c2 = 0; c2 < sz(CI[c1]); c2++){
            a = CI[c1][c2];

            if(XOR[a] == prev){
                ll x = XOR[a];
                b = CI[c1][c2-1];

                ll a1 = M2[{A[a],x}];
                ll b1 = M2[{A[a],x}];
                ll a2 = M2[{A[b],x}];
                ll b2 = M2[{B[b],x}];

                if(par(a1) != par(b1)){
                    M[x]--;
                    merg(a1,b1);
                }

                if(par(a2) != par(b2)){
                    M[x]--;
                    merg(a2,b2);
                }

            }
            prev = XOR[a];
        }
    }
    */
    for(int c1 = 0; c1 < m; c1++){
        ll a = A[c1];
        ll b = B[c1];
        ll x = XOR[c1];
        ll x1 = x*base+a;
        ll x2 = x*base+b;
        ll a2 = par(M2[x1]);
        ll b2 = par(M2[x2]);

        if(a2 != b2){
            M[x]--;
            merg(a2,b2);
        }
    }


    ll ans = 0;

    for(int c1 = 0; c1 < sz(xorlist); c1++){
        ans += TWOS[M[xorlist[c1]]];
       // cout << M[xorlist[c1]] << " " << xorlist[c1] << "\n";
        ans = mod(ans);
    }

    ans += mod((TWOS[k]-sz(xorlist)) * TWOS[n]);
    ans = mod(ans);
    cout << ans << "\n";

    return 0;
}