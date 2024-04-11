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
  cout << ""; for(int i = 0; i < v.size(); i++) {if (i) cout << " "; cout << v[i];} return cout << "";
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
      cin >> n;
      vi a(n), b(n), c(n);
      forn(i, n){
        cin >> a[i];
      }
      forn(i, n){
        cin >> b[i];
      }
      forn(i, n){
        cin >> c[i];
      }
      vi v(n);
      v[0] = a[0];
      for(int i=1; i<n-1; i++){
        if(a[i] == v[i-1]){
          v[i] = b[i];
        }else{
          v[i] = a[i];
        }
      }
      if(v[n-2] == a[n-1]){
        if(v[0] == b[n-1]){
          v[n-1] = c[n-1];
        }else{
          v[n-1] = b[n-1];
        }
      }else if(v[n-2] == b[n-1]){
        if(v[0] == a[n-1]){
          v[n-1] = c[n-1];
        }else{
          v[n-1] = a[n-1];
        }
      }else{
        if(v[0] == a[n-1]){
          v[n-1] = b[n-1];
        }else{
          v[n-1] = a[n-1];
        }
      }
      cout << v << endl;
    }
}