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
    ll n;
    cin >> n;
    vl x(n);
    bool unique = true;
    pii k;
    vi p(n, -1);
    p[0] = 0;
    for(int i=1; i<n; i++){
      cout << "XOR " << 1 << " " << i+1 << endl;
      cin >> x[i];
      if(p[x[i]] != -1){
        unique = false;
        k = {p[x[i]], i};
      }else{
        p[x[i]] = i;
      }
    }
    if(unique){
      //find v[0]
      cout << "OR " << 1 << " " << p[2]+1 << endl;
      ll ans;
      cin >> ans;
      int par = ans%2;
      cout << "OR " << 1 << " " << p[1]+1 << endl;
      cin >> ans;
      ll vnot = (ans - 1) + par;
      cout << "! ";
      forn(i, n){
        cout << (x[i]^vnot) << " ";
      }
      cout << endl;
    }else{
      cout << "OR " << k.f+1 << " " << k.s+1 << endl;
      ll ans;
      cin >> ans;
      cout << "! ";
      forn(i, n){
        cout << (x[i]^ans^x[k.f]) << " ";
      }
      cout << endl;
    }

}