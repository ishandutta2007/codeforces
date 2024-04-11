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

struct DSU{
    vi parent;//Parent of each element. If parent[i] = i, it is a root of a set
    vi num_elements;//Number of elements in a set given by a root.
    int n;

    DSU(int n):n(n),parent(n),num_elements(n,1){
        forn(i,n){
            parent[i] = i;
        }
    }

    //Merge the two sets that x and y are in.
    void join(int x, int y){
        if(parent[x] == parent[y]){
            return; //already in same set
        }
        int xroot = root(x);
        int yroot = root(y);

        if(num_elements[xroot] < num_elements[yroot]){
            parent[xroot] = yroot;
            num_elements[yroot] += num_elements[xroot];
        }else{
            parent[yroot] = xroot;
            num_elements[xroot] += num_elements[yroot];
        }
    }

    //Find root of an element. Uses path splitting for efficiency. (compresses path)
    int root(int x){
        while (parent[x] != x){
            int prev = x;
            x = parent[x];
            parent[prev] = parent[x];
        }
        return x;
    }

    //Whether two elements are in the same set.
    bool together(int x, int y){
        return root(x) == root(y);
    }
};

int main(){
    fast_io();
    int m, n;
    cin >> m >> n;
    vpl a(m);
    vl b(n);
    forn(i, m){
      ll x;
      cin >> x;
      a[i] = mp(x, i);
    }
    forn(i, n){
      cin >> b[i];
    }
    vector<vi> vals(m);
    vector<pair<ll, pii> > coords;
    forn(i, m){
      int si;
      cin >> si;
      vals[i] = vi(si);
      forn(j, si){
        cin >> vals[i][j];
        vals[i][j]--;
        coords.pb(mp(a[i].f + b[vals[i][j]], mp(i, vals[i][j])));
      }
    }
    sort(coords.begin(), coords.end());
    DSU d(n);
    vi sets(m, -1);
    ll tot = 0;
    //cout << "DS " << coords.size() << endl;
    for(int i=coords.size()-1; i>=0; i--){

      int ii = coords[i].s.f;
      int jj = coords[i].s.s;
      if(sets[ii] == -1){
        //cout << ii << " JFKDLSJFDS\n";
        sets[ii] = jj;
      }else{
        //cout << "HI\n";
        if(d.together(jj, sets[ii])){
          tot += coords[i].f;
        }else{
          d.join(jj, sets[ii]);
          //cout << "FDS " << jj << sets[ii] << endl;
        }
      }
      //cout << "TEST\n";
    }
    //cout << coords << endl;
    cout << tot << "\n";
    /*
    sort(a.begin(), a.end());
    ll tot = 0;
    DSU d(n);
    for(int i=m-1; i>=0; i--){
      int row = a[i].s;
      vpl roots;
      for(int x: vals[row]){
        roots.pb(mp(d.root(x), x));
      }
      sort(roots.begin(), roots.end(), [&b](pll aa, pll bb){
        if(aa.f != bb.f) return aa.f < bb.f;
        else return b[aa.s] > b[bb.s];
      });
      forn(j, roots.size()-1){
        d.join(roots[j].s, roots[j+1].s);
        if(roots[j].f == roots[j+1].f){
          tot += b[roots[j+1].s] + a[i].f;
        }
      }
    }

    cout << tot << endl;
    */

}