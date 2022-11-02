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
    int n;
    cin >> n;
    vl v(n);
    vl pref(n);
    vl x(n);
    forn(i, n){
      cin >> v[i];
      pref[i] = v[i] + (i>0?pref[i-1]:0);
      x[i] = v[i] ^ (i>0?x[i-1]:0);
    }
    //cout << pref << "\n";

    set<pair<ll, int>> s;
    s.insert({v[0]+pref[0], 0});
    s.insert({v[1]+pref[1], 1});
    int cnt=0;
    for(int i=2; i<n; i++){
      ll search = pref[i-1] - v[i];
      auto it = s.lower_bound({search, 0});
      while(it != s.end()){
        if(it->s < i-1){
          //cout << it->s << " " << i << "\n";
          if((v[i] ^ v[(*it).s]) == pref[i-1]-pref[it->s]){
            cnt++;
            //cout << "^works\n";
          }
        }
        it++;
      }
      s.insert({v[i]+pref[i], i});
    }
    cout << cnt << "\n";
}