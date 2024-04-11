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


int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
      int n;
      ll l;
      cin >> n >> l;
      vl a(n);
      forn(i, n){
        cin >> a[i];
      }
      vl segs;
      segs.pb(a[0]);
      forn(i, n-1){
        segs.pb(a[i+1]-a[i]);
      }
      segs.pb(l-a[n-1]);

      vector<double> ltimes(n+2), rtimes(n+2);
      ltimes[0] = 0;
      for(int i=1; i<=n+1; i++){
        ltimes[i] = ltimes[i-1] + (double)segs[i-1]/i;
      }

      rtimes[n+1] = 0;
      for(int i=n; i>=0; i--){
        rtimes[i] = rtimes[i+1] + (double)segs[i]/(n-i+1);
      }
      //cout << ltimes << "\n";
      //cout << rtimes << "\n";

      forn(i, n+1){
        if(ltimes[i] <= rtimes[i] && ltimes[i+1] >= rtimes[i+1]){
          int lspeed = i+1;
          int rspeed = (n-i+1);
          double seglength = segs[i];
          if(ltimes[i] <= rtimes[i+1]){
            seglength -= lspeed*(rtimes[i+1]-ltimes[i]);
          }else{
            seglength -= rspeed*(ltimes[i]-rtimes[i+1]);
          }
          cout << setprecision(16) << max(ltimes[i], rtimes[i+1])+seglength/(n+2) <<"\n";
          break;
        }
      }
    }

}