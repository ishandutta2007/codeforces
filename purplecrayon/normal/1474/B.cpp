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
const int MAXN = 1e5+10, MAXM = 1e2+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

ll nxt[MAXN];
bool c[MAXN];

void pre(){
    memset(c, 0, sizeof(c));
    for (int i = 2; i < MAXN; i++) if (!c[i]){
        for (int j = 2*i; j < MAXN; j+=i) c[j]=1;
    }
    c[1]=0;
    int p=-1;
    for (int i = MAXN-1; i >= 0; i--){
        if (c[i]) nxt[i] = p;
        else p = nxt[i] = i;
    }
}
void solve(){
    //can't be prime or square of prime;
    //must be (d+1)*(2*d+1)
    //could be bad if d+1 is composite, or 2*d+1 is composite

    ll d; cin >> d;
    ll a=nxt[(d+1)];
    ll b=nxt[a+d];
    cout << a*b << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c; pre();
    while (t_c--) solve();
}