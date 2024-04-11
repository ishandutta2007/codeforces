


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

struct pt {
  li x,y;
  bool operator==(pt const& o) const { return tie(x,y) == tie(o.x,o.y); }
  bool operator!=(pt const& o) const { return tie(x,y) != tie(o.x,o.y); }
  bool operator<(pt const& o) const { return tie(x,y) < tie(o.x,o.y); }
  bool operator>(pt const& o) const { return tie(x,y) > tie(o.x,o.y); }
  bool operator<=(pt const& o) const { return tie(x,y) <= tie(o.x,o.y); }
};

pt operator+(pt const& a, pt const& b) {
  return pt{a.x+b.x, a.y+b.y};
}

pt operator-(pt const& a, pt const& b) {
  return pt{a.x-b.x, a.y-b.y};
}

li dot(pt const& a, pt const& b) {
  return a.x*b.x+a.y*b.y;
}


li det(pt const& a, pt const& b) {
  return a.x*b.y-a.y*b.x;
}

ostream& operator<<(ostream& s, pt const& a) {
  return s<<make_tuple(a.x,a.y);
}

void add_point(vector<pt> &s, int sign, pt p) {
  while(s.size() >= 2 &&
        det((*(s.end()-2))-s.back(), p-s.back())*sign >= 0){
    s.pop_back();
  }
  s.push_back(p);
}

vector<pt> convex_hull(vector<pt> A){
  if (A.size() <= 2) return A;
  vector<pt> c[2];
  sort(A.begin(), A.end());
  for(li i = 0; i < (li)(2); ++i) for(pt p : A) add_point(c[i], 2 * i - 1, p);
  c[0].insert(c[0].end(), c[1].rbegin() + 1, c[1].rend() - 1);
  return c[0];
}


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<pt> A(n);
  for(li i = 0; i < (li)(n); ++i) cin>>A[i].x>>A[i].y;
  vi I(n); iota(begin(I), end(I),0);
  sort(begin(I), end(I), [&](int i, int j) { return A[i] > A[j];});
  vi ans;
  ans.emplace_back(I.back());
  I.pop_back();
  string s; cin>>s;

  for(char c : s) {

    vector<pt> B;
    B.emplace_back(A[ans.back()]);
    for(int i : I) B.emplace_back(A[i]);
    B = convex_hull(B);

    int nb = B.size();
    int ix=-1;

    if(c == 'R') {
      for(li i = 0; i < (li)(nb); ++i) if(B[i] == A[ans.back()]) {
        ix = (i+1)%nb;
      }
    } else {
      for(li i = 0; i < (li)(nb); ++i) if(B[i] == A[ans.back()]) {
        ix = (i-1+nb)%nb;
      }
    }
    assert(ix != -1);

    int jx = -1;
    for(li i = 0; i < (li)(I.size()); ++i) if(A[I[i]] == B[ix]) jx = i;
    assert(jx != -1);

    ans.emplace_back(I[jx]);
    swap(I[jx],I.back());
    I.pop_back();
  }
  ans.emplace_back(I[0]);
  for(int i : ans) {
    cout << i+1 << ' ';
  }
  cout << endl;
  return 0;
}