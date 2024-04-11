


 #include <stdio.h>
 #include <bits/stdc++.h>






using namespace std;




template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a);
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a);

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, multiset<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

template<class T>
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}







using li = long long int;
using lu = long long unsigned;
using ld = long double;


using pii = tuple<li, li>;
using piii = tuple<li, li, li>;
using piiii = tuple<li, li, li, li>;
using vi = vector<li>;
using vii = vector<pii>;
using viii = vector<piii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

struct empty_t {};

namespace tuple_access {

  struct xx_t {} xx;
  struct yy_t {} yy;
  struct zz_t {} zz;
  struct ww_t {} ww;

  template<class T>
  typename tuple_element<0,T>::type& operator^(T& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type const& operator^(T const& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type&& operator^(T&& v, xx_t) { return get<0>(v); }

  template<class T>
  typename tuple_element<1,T>::type& operator^(T& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type const& operator^(T const& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type&& operator^(T&& v, yy_t) { return get<1>(v); }

  template<class T>
  typename tuple_element<2,T>::type& operator^(T& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type const& operator^(T const& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type&& operator^(T&& v, zz_t) { return get<2>(v); }

  template<class T>
  typename tuple_element<3,T>::type& operator^(T& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type const& operator^(T const& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type&& operator^(T&& v, ww_t) { return get<3>(v); }
}
using namespace tuple_access;


int ilog2(int x){ return 31 - __builtin_clz(x); }

template <class T>
struct identity : std::unary_function <T, T> {
  T operator() (const T& x) const {return x;}
};

template<class T>
T& smin(T& x, T const& y) { x = min(x,y); return x; }

template <class T>
T& smax(T& x, T const& y) { x = max(x, y); return x; }


template<typename T>
T isqrt(T const&x){
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(sqrtl(x));
  while(ret>0 && ret*ret>x) --ret;
  while(x-ret*ret>2*ret) ++ret;
  return ret;
}

template<typename T>
T icbrt(T const&x) {
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(cbrt(x));
  while(ret>0 && ret*ret*ret>x) --ret;
  while(x-ret*ret*ret>3*ret*(ret+1)) ++ret;
  return ret;
}



struct MaxFlow {
  struct Edge {
    li from, to, cap, flow, index;
    Edge(li from, li to, li cap, li flow, li index) :
      from(from), to(to), cap(cap), flow(flow), index(index) {}
  };

  li N;
  vector<vector<Edge> > G;
  vector<li> excess;
  vector<li> dist, active, count;
  queue<li> Q;

  MaxFlow(li N = 0) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) { }

  li addNode() {
    N += 1;
    G.emplace_back(); excess.emplace_back(); dist.emplace_back(); active.emplace_back(); count.emplace_back(); count.emplace_back();
    return N-1;
  }

  void addEdge(li from, li to, li cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void enqueue(li v) {
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); }
  }

  void push(Edge &e) {
    li amt = min(excess[e.from], e.cap - e.flow);
    if(dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    enqueue(e.to);
  }

  void gap(li k) {
    for(li v = 0; v < (li)(N); ++v) {
      if(dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      enqueue(v);
    }
  }

  void relabel(li v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for(Edge& e : G[v]) if(e.cap - e.flow > 0) {
        dist[v] = min(dist[v], dist[e.to] + 1);
      }
    count[dist[v]]++;
    enqueue(v);
  }

  void discharge(li v) {
    for(li i = 0; excess[v] > 0 && i < (li)G[v].size(); ++i) push(G[v][i]);
    if(excess[v] > 0) {
      if(count[dist[v]] == 1) {
        gap(dist[v]);
      } else {
        relabel(v);
      }
    }
  }

  li flow(li s, li t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for(Edge& e : G[s]) {
      excess[s] += e.cap;
      push(e);
    }
    while (!Q.empty()) {
      li v = Q.front();
      Q.pop();
      active[v] = false;
      discharge(v);
    }
    li totflow = 0;
    for(Edge& e : G[s]) totflow += e.flow;
    return totflow;
  }
};




int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  li n,m; cin>>n>>m;

  set<li> aCS;
  aCS.insert(0);
  aCS.insert(2e9);

  vector<tuple<li,li,li,li>> RS;

  for(li i = 0; i < (li)(m); ++i) {
    li x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    x2++; y2++;

    RS.emplace_back(x1,y1,x2,y2);

    aCS.insert(x1);
    aCS.insert(x2);
    aCS.insert(y1);
    aCS.insert(y2);

    aCS.insert(x1-1);
    aCS.insert(x2-1);
    aCS.insert(y1-1);
    aCS.insert(y2-1);

    aCS.insert(x1+1);
    aCS.insert(x2+1);
    aCS.insert(y1+1);
    aCS.insert(y2+1);
  }

  vi CS(begin(aCS), end(aCS));

  MaxFlow F;
  li S = F.addNode();
  li T = F.addNode();

  vi A(CS.size()-1),B(CS.size()-1);
  for(li i = 0; i < (li)(CS.size()-1); ++i) { A[i] = F.addNode(); F.addEdge(S,A[i],CS[i+1]-CS[i]); }
  for(li i = 0; i < (li)(CS.size()-1); ++i) { B[i] = F.addNode(); F.addEdge(B[i],T,CS[i+1]-CS[i]); }

  for(li i = 0; i < (li)(CS.size()-1); ++i) for(li j = 0; j < (li)(CS.size()-1); ++j) {
    bool ok = 0;
    for(auto p : RS) {
      li x1,y1,x2,y2;
      tie(x1,y1,x2,y2) = p;
      if(CS[i] >= x1 && CS[i+1] <= x2 && CS[j] >= y1 && CS[j+1] <= y2) ok = 1;
    }
    if(ok) F.addEdge(A[i],B[j],1e9);
  }

  li r = F.flow(S, T);
  cout << r << endl;
  return 0;
}