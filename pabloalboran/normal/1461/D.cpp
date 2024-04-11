#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define printArr(arr, n) forn(i, n){if (i) cout << " "; cout << arr[i];} cout << endl;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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

//Custom hash function for anti-hacking on unordered_map and unordered_set
//Use: unordered_map<whatever, whatever, custom_hash> safe_map;
struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       // http://xorshift.di.unimi.it/splitmix64.c
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

unordered_map<ll, bool, custom_hash> safe_map;

void process(vl& w){
  ll mi = w[0];
  ll ma = w[0];
  ll su = 0;
  int n = w.size();
  forn(i, n){
    mi = min(mi, w[i]);
    ma = max(ma, w[i]);
    su += w[i];
  }
  safe_map[su] = true;
  if(ma == mi) return;
  vl left, right;
  forn(i, n){
    if(w[i] <= (ma+mi)/2){
      left.pb(w[i]);
    }else{
      right.pb(w[i]);
    }
  }
  process(left);
  process(right);
}
int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
      int n, q;
      cin >> n >> q;
      vl v(n);
      forn(i, n){
        cin >> v[i];
      }
      safe_map = unordered_map<ll, bool, custom_hash>();
      process(v);

      forn(j, q){
        ll x;
        cin >> x;
        if(safe_map[x]){
          cout << "Yes\n";
        }else{
          cout << "No\n";
        }
      }

    }
}