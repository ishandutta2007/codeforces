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
//For max seg trees
struct max_t {
  ll val;
  static const long long null_v = 0;

  max_t(): val(0) {}
  max_t(ll v): val(v) {}

  max_t op(max_t& other) {
    return max_t(max(val, other.val));
  }

  max_t lazy_op(max_t v, int size) {
    return max_t(val + v.val);
  }
};

template <typename num_t>
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  segtree(): n(0){}
  segtree(int s): n(s), tree(4*s,0) {}

  segtree(int s, vector<long long>& arr): n(s), tree(4*s,0) {
    init(0, 0, n - 1, arr);
  }

  void init(int s, vector<long long>& arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, vector<long long>& arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int i, ll v){
    /*Adds v to index i*/
    update(0, 0, n-1, i, num_t(v));
  }

  void set_val(int i, ll v){
    /*Sets index i to value v*/
    update(i, v-query(i));
  }

  num_t update(int i, int tl, int tr, int q, num_t v) {

    if (tl > tr || tr < q || q < tl) return tree[i];
    if (tl == tr && q == tl){
      tree[i].val += v.val;
    }
    if (tl == tr) return tree[i];

    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, q, v),
          b = update(2 * i + 2, mid + 1, tr, q, v);
    return tree[i] = a.op(b);
  }

  ll query(int l, int r) {
    return query(0, 0, n-1, l, r).val;
  }

  ll query(int i){
    return query(0, 0, n-1, i, i).val;
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {

    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return num_t::null_v;

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }
};

int main(){
    fast_io();
    int n, k;
    cin >> n >> k;
    vi v(n);
    readVec(v);
    set<int> s;
    forn(i, n){
      v[i] -= i;
      s.insert(v[i]);
    }
    map<int, int> m;
    int ind = 0;
    for(auto it = s.begin(); it != s.end(); it++){
      m[*it] = ind++;
    }
    forn(i, n){
      v[i] = m[v[i]];
    }

    if(k==0){
      //cout << "k is zero" << endl;
      segtree<max_t> s(n);
      forn(i, n){
        s.set_val(v[i], s.query(0, v[i])+1);
      }
      cout << n-s.query(0, n-1);
    }else{
      vi b(k);
      readVec(b);
      ll ans = 0;
      //cout << b << endl;
      forn(i, k-1){
        if(v[b[i]-1] > v[b[i+1]-1]){
          cout << -1;
          return 0;
        }
      }
      //cout << v << endl;
      segtree<max_t> s(n);
      forn(i, b[0]-1){
        if(v[i]>v[b[0]-1]){
          ans+=0;
        }else{
          s.set_val(v[i], s.query(0, v[i])+1);
        }
      }
      ans += b[0]-1-s.query(0, n-1);
      //cout << "ans1 " << ans << endl;

      s = segtree<max_t>(n);
      forn(i, n-b[k-1]){
        int x = v[i+b[k-1]];
        if(x<v[b[k-1]-1]){
          ans+=0;
        }else{
          s.set_val(x-v[b[k-1]-1], s.query(0, x-v[b[k-1]-1])+1);

        }
      }
      ans += n-b[k-1]-s.query(0, n-1);
      //cout << "ans2 " << ans << endl;
      for(int i=0; i<k-1; i++){
        s = segtree<max_t>(v[b[i+1]-1]-v[b[i]-1]+1);
        forn(j, b[i+1]-b[i]-1){
          int x = v[b[i]+j];
          if(x<v[b[i]-1] || x>v[b[i+1]-1]){
            ans+=0;
          }else{
            s.set_val(x-v[b[i]-1], s.query(0, x-v[b[i]-1])+1);
          }
        }
        ans += b[i+1]-b[i]-1-s.query(0, v[b[i+1]-1]-v[b[i]-1]);
        //cout << "ansd " << ans << endl;
      }
      //cout << "HI" << "\n";
      cout << ans << "\n";

    }

}