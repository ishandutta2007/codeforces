#include<bits/stdc++.h>
using namespace std;
/**
 * @brief Convex-Hull-Trick-Add-Monotone
 * @docs docs/convex-hull-trick-add-monotone.md
*/
template< typename T, bool isMin >
struct ConvexHullTrickAddMonotone {
#define F first
#define S second
  using P = pair< T, T >;
  deque< P > H;

  ConvexHullTrickAddMonotone() = default;

  bool empty() const { return H.empty(); }

  void clear() { H.clear(); }

  inline int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }

  using D = long double;

  inline bool check(const P &a, const P &b, const P &c) {
    if(b.S == a.S || c.S == b.S)
      return sgn(b.F - a.F) * sgn(c.S - b.S) >= sgn(c.F - b.F) * sgn(b.S - a.S);

    //return (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);
    return
        D(b.F - a.F) * sgn(c.S - b.S) / D(abs(b.S - a.S)) >=
        D(c.F - b.F) * sgn(b.S - a.S) / D(abs(c.S - b.S));
  }

  void add(T a, T b) {
    if(!isMin) a *= -1, b *= -1;
    P line(a, b);
    if(empty()) {
      H.emplace_front(line);
      return;
    }
    if(H.front().F <= a) {
      if(H.front().F == a) {
        if(H.front().S <= b) return;
        H.pop_front();
      }
      while(H.size() >= 2 && check(line, H.front(), H[1])) H.pop_front();
      H.emplace_front(line);
    } else {
      assert(a <= H.back().F);
      if(H.back().F == a) {
        if(H.back().S <= b) return;
        H.pop_back();
      }
      while(H.size() >= 2 && check(H[H.size() - 2], H.back(), line)) H.pop_back();
      H.emplace_back(line);
    }
  }

  inline T get_y(const P &a, const T &x) {
    return a.F * x + a.S;
  }

  T query(T x) {
    assert(!empty());
    int l = -1, r = H.size() - 1;
    while(l + 1 < r) {
      int m = (l + r) >> 1;
      if(get_y(H[m], x) >= get_y(H[m + 1], x)) l = m;
      else r = m;
    }
    if(isMin) return get_y(H[r], x);
    return -get_y(H[r], x);
  }

  T query_monotone_inc(T x) {
    assert(!empty());
    while(H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x)) H.pop_front();
    if(isMin) return get_y(H.front(), x);
    return -get_y(H.front(), x);
  }

  T query_monotone_dec(T x) {
    assert(!empty());
    while(H.size() >= 2 && get_y(H.back(), x) >= get_y(H[H.size() - 2], x)) H.pop_back();
    if(isMin) return get_y(H.back(), x);
    return -get_y(H.back(), x);
  }

#undef F
#undef S
};
typedef long long ll;
ll INF=1000000000;
int main(){
  int N,M;
  cin>>N>>M;
  N++;
  M++;
  vector<vector<int>> A(N,vector<int>(M,0));
  for(int i=0;i<N;i++){
    string S;
    cin>>S;
    for(int j=0;j<M;j++){
      if(S[j]=='1'){
        A[i][j]=1;
      }
    }
  }
  vector<vector<ll>> X(N,vector<ll>(M,INF));
  for(int i=0;i<N;i++){
    bool f=false;
    ConvexHullTrickAddMonotone<ll,true> CHT;
    for(int j=0;j<M;j++){
      if(A[i][j]){
        CHT.add(-2*j,j*j);
        f=true;
      }
      if(f){
        X[i][j]=CHT.query_monotone_inc(j)+j*j;
      }
    }
    f=false;
    ConvexHullTrickAddMonotone<ll,true> CHT2;
    for(int j=M-1;j>=0;j--){
      if(A[i][j]){
        CHT2.add(-2*j,j*j);
        f=true;
      }
      if(f){
        X[i][j]=min(X[i][j],CHT2.query_monotone_dec(j)+j*j);
      }
    }
  }
  vector<vector<ll>> Y(N,vector<ll>(M,INF));
  ll ANS=0;
  for(int j=0;j<M;j++){
    ConvexHullTrickAddMonotone<ll,true> CHT;
    for(int i=0;i<N;i++){
      CHT.add(-2*i,i*i+X[i][j]);
      Y[i][j]=CHT.query_monotone_inc(i)+i*i;
    }
    ConvexHullTrickAddMonotone<ll,true> CHT2;
    for(int i=N-1;i>=0;i--){
      CHT2.add(-2*i,i*i+X[i][j]);
      Y[i][j]=min(Y[i][j],CHT2.query_monotone_dec(i)+i*i);
      ANS+=Y[i][j];
    }
  }
  cout<<ANS<<"\n";
}