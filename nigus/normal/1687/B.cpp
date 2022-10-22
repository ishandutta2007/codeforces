#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;
 
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
 
ll random2(){
    return (1ll << 31ll)*eng()+eng();
}
 
ll n,m,k,q,T;
 
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;
 
const int MAXN = 300006;
 
ll ask(set<int> S){
    string s = "";
    rep(c1,0,m){
        if(S.find(c1) != S.end()){
            s += '1';
        }
        else{
            s += '0';
        }
    }
    cout <<"? "<< s << "\n";
    fflush(stdout);
    ll x;
    cin >> x;
    return x;
}

vi ind;
vl W;

bool comp(ll i, ll j){
    return W[i] < W[j];
}

int main() {
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);
 
    ll a,b,c,d,e;
    
    cin >> n >> m;

    rep(c1,0,m){
        set<int> temp;
        temp.insert(c1);
        ll w = ask(temp);
        W.push_back(w);
        ind.push_back(c1);
    }
    sort(all(ind), comp);

    ll ans = 0;
    set<int> S;
    rep(c1,0,m){
        int i = ind[c1];
        S.insert(i);
        ll x = ask(S);
        if(x < ans+W[i]){
            S.erase(i);
        }
        else{
            ans = x;
        }
    }
    cout <<"! "<< ans << "\n";
    fflush(stdout);
 
    return 0;
}