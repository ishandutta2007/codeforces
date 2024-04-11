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
      vl x(4), y(4);
      forn(i, 4){
        cin >> x[i] >> y[i];
      }
      ll ans = 1e15;
      for(int b1 = 1; b1 < 4; b1++){
        vl pts;
        int b = b1;
        int a = 0;
        int c = (b == 1 ? 2 : 1);
        int d = (b == 3 ? 2 : 3);
        if(x[a] > x[b]) swap(a, b);
        if(x[c] > x[d]) swap(c, d);
        ll s = x[b] - x[a] + x[d] - x[c];
        int sm;
        if(x[a] > x[c]){
          swap(a, c);
          swap(b, d);
        }
        if(x[c] >= x[b]){
          sm = -2;
          s += 2*(x[c] - x[b]);
          pts.pb(x[c] - x[b]);
          pts.pb(x[d] - x[a]);
        }else if(x[d] <= x[b]){
          sm = 0;
          pts.pb(max(x[d] - x[a], x[b] - x[c]));
        }else{
          sm = 0;
          pts.pb(x[d] - x[a]);
        }

        for(int b2 = 1; b2 < 4; b2++){
          if(b2 == b1) continue;
          vl pts2;
          for(int l: pts) pts2.pb(l);
          b = b2;
          a = 0;
          c = (b == 1 ? 2 : 1);
          d = (b == 3 ? 2 : 3);
          if(y[a] > y[b]) swap(a, b);
          if(y[c] > y[d]) swap(c, d);
          ll s2 = y[b] - y[a] + y[d] - y[c];
          if(y[a] > y[c]){
            swap(a, c);
            swap(b, d);
          }
          int sm2 = 0;
          if(y[c] >= y[b]){
            sm2 = -2;
            s2 += 2*(y[c] - y[b]);
            pts2.pb(y[c] - y[b]);
            pts2.pb(y[d] - y[a]);
          }else if(y[d] <= y[b]){
            pts2.pb(max(y[d] - y[a], y[b] - y[c]));
          }else{
            pts2.pb(y[d] - y[a]);
          }

          sort(pts2.begin(), pts2.end());
          ll k;
          if(sm + sm2 == 0){
            k= s+s2;
          }else if(sm + sm2 == -2){
            k= s+s2-2*pts2[0];
          }else if(sm + sm2 == -4){
            k= s+s2 - 2*(pts2[0] + pts2[1]);
          }
          //cout << "b1: " << b1 << " b2: " << b2 << " k: " << k << " " << pts2 << " s, s2: " << s << " " << s2 << " sm, sm2:  " << sm << " " << sm2 << "\n";
          ans = min(ans, k);
        }
      }
      cout << ans << "\n";
    }
}