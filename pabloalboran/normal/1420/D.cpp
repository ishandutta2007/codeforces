#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define printArr(arr, n) forn(i, n){if (i) cout << " "; cout << arr[i];} cout << endl;
#define pb push_back
#define mp make_pair
#define MOD 998244353
#define f first
#define s second

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
void file_io(string taskname){
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}
ll mpow(ll base, ll exp) {
  ll res = 1;
  while (exp) {
    if (exp % 2 == 1){
        res = (res * base) % MOD;
    }
    exp >>= 1;
    base = (base * base) % MOD;
  }
  return res;
}

ll minv(ll base) {
    return mpow(base, MOD - 2);
}


int main(){
    fast_io();
    vl fac(300010);
    fac[0] = 1;
    for(int i=1; i<fac.size(); i++){
      fac[i] = (fac[i-1]*i)%MOD;
    }
    int n, k;
    cin >> n >> k;
    vl l(n), r(n);
    vpl v;
    forn(i, n){
      cin >> l[i] >> r[i];
      v.pb(mp(l[i], 0));
      v.pb(mp(r[i], 1));
    }
    sort(v.begin(), v.end());
    int curr = 0;
    ll tot = 0;
    for(auto event: v){
      if(event.s == 0){
        if(curr >= k-1){
          tot += ((fac[curr] * minv(fac[k-1]))%MOD)*minv(fac[curr-k+1]) %MOD;
          //cout << fac[curr] << " " << ((fac[curr] * minv(k-1))%MOD)*minv(curr-k+1) %MOD << " yo \n";
          tot %= MOD;
        }
        //cout << curr << "HI\n";
        curr++;

      }else{
        curr--;
      }
    }

    cout << tot << endl;

}