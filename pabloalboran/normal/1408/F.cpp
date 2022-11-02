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

vpi q;

void condense(vi& v){
  if(v.size() == 1){
    return;
  }
  vi u1, u2;
  forn(i, v.size()/2){
    u1.pb(v[i]);
    u2.pb(v[i+v.size()/2]);
  }
  condense(u1);condense(u2);
  forn(i, v.size()/2){
    q.pb(mp(u1[i], u2[i]));
  }
}
int main(){
    fast_io();
    int n;
    cin >> n;
    vi v(n);
    forn(i, n){
      v[i] = i;
    }
    vector<vi> groups;
    ll m = n;
    int i=0;
    ll sz = 1;
    while(m>0){
      if(m%2 == 1){
        vi x;
        forn(j, sz){
          x.pb(v[i]);
          i++;
        }
        groups.pb(x);
        condense(groups[groups.size()-1]);
      }
      m >>= 1;
      sz <<= 1;
    }

    vi build = groups[0];
    int ind = 0;
    for(int i=1; i<groups.size()-1; i++){
      while(build.size() < groups[i].size()){
        sz = build.size();
        forn(j, sz){
          q.pb(mp(build[j], groups[groups.size()-1][ind]));
          build.pb(groups[groups.size()-1][ind]);
          ind++;
        }
      }
      sz = build.size();
      forn(j, sz){
        q.pb(mp(build[j], groups[i][j]));
        build.pb(groups[i][j]);
      }
    }

    cout << q.size() << "\n";
    forn(i, q.size()){
      cout << q[i].f+1 << " " << q[i].s+1 <<"\n";
    }
}