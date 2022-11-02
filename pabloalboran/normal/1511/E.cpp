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


int main(){
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<vb> v(n, vb(m));
    ll cnt = 0;
    forn(i, n){
      forn(j, m){
        char c;
        cin >> c;
        if(c=='o'){v[i][j] = true; cnt++;}
      }
    }
    vl f(n+m);
    f[0] = 0;
    f[1] = 0;
    for(int i=2; i<n+m; i++){
      f[i] = (mpow(2, i-2)+2*f[i-2]+f[i-1])%MOD;
    }
    ll tot = 0;
    // ll add = mpow(2, cnt-2);
    forn(i, n){
      int curr = 0;
      forn(j, m){
        if(v[i][j]) curr++;
        else{
          tot = (tot+f[curr]*mpow(2, cnt-curr))%MOD;
          curr = 0;
        }
        // if(i < n-1 && v[i][j] && v[i+1][j]) tot = (tot+add)%MOD;
        // if(j < m-1 && v[i][j] && v[i][j+1]) tot = (tot+add)%MOD;
      }
      tot = (tot+f[curr]*mpow(2, cnt-curr))%MOD;
    }
    forn(j, m){
      int curr = 0;
      forn(i, n){
        if(v[i][j]) curr++;
        else{
          tot = (tot+f[curr]*mpow(2, cnt-curr))%MOD;
          curr = 0;
        }
      }
      tot = (tot+f[curr]*mpow(2, cnt-curr))%MOD;
    }
    cout << tot << "\n";
}