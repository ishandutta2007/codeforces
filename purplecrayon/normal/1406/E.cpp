#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

ll po(ll b, ll p){
    ll r=1;
    for (; p; p/=2, b=b*b) if (p&1) r=r*b;
    return r;
}
bool p[MAXN];
int A(int x){
    cout << "A " << x << endl;
    int v; cin >> v;
    return v;
}
int B(int x){
    cout << "B " << x << endl;
    int v; cin >> v;
    return v;
}
void C(int x){
    cout << "C " << x << endl;
    exit(0);
}

void sieve(int n){
    fill(p, p+n+1, 1);
    for (ll i = 2; i <= n; i++) if (p[i]){
        for (ll j = i*i; j <= n; j += i) p[j]=0;
    }
}

int n;
vector<int> cand;

int rec(int l, int r, int s){
    if (l == r) return cand[l];
    int m=(l+r)/2;

    int cnt=0;
    for (int i = l; i <= m; i++){
        int v=B(cand[i]);
        cnt+=v;
    }

    int ns = s-cnt;
    int rl = A(1);
    if (rl != ns){
        assert(rl == ns+1);
        //its in the left side
        return rec(l, m, rl);
    } else {
        //its not in the left side
        return rec(m+1, r, rl);
    }
}
ll m=1;
void solve(){
    cin >> n; sieve(n);
    if (n == 1) C(1);
    for (ll i = 2; i*i <= n; i++) if (p[i]){
        B(i);
        if (A(i)){
            //bin search the power
            int lo=0, hi=0;
            
            ll c=1;
            while (c <= n) c *= i, hi++;

            int mid=(lo+hi)/2;
            while (lo < mid && mid < hi){
                if (A(po(i, mid))) lo=mid;
                else hi=mid;
                mid=(lo+hi)/2;
            }
            m *= po(i, lo);
        }
    }
    //either some big prime or 1
    for (ll i = 2; i <= n; i++) if (i*i > n && p[i]){ //only big primes
        cand.push_back(i);
    }
    int x=rec(0, sz(cand)-1, A(1)); //size also includes 1
    B(x); int v=A(x);
    if (!v) C(1*m);
    else C(x*m); 
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}