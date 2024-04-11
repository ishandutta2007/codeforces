#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
#include <set>
#include <tuple>
#include <utility>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

// ------------------------------------------------------------------------------

using lli = long long int;
using llu = long long unsigned;

// ------------------------------------------------------------------------------

#define FOR(i, n) for (lli i = 0; i < (n); ++i)
#define FORU(i, j, k) for (lli i = (j); i <= (k); ++i)
#define FORD(i, j, k) for (lli i = (j); i >= (k); --i)

#define X(x) get<0>(x)
#define Y(x) get<1>(x)
#define Z(x) get<2>(x)

// ------------------------------------------------------------------------------

// <functional>
// plus, minus, multiplies, divides, modulus, negate
// equal_to, not_equal_to, greater, less, greater_equal, less_equal
// logical_and, logical_or, logical_not
// bit_and, bit_or, bit_xor

template<typename T>
struct minf{
  T operator()(T const& a, T const& b){
    return min(a, b);
  }
};

template<typename T>
struct maxf{
  T operator()(T const& a, T const& b){
    return max(a, b);
  }
};

// ------------------------------------------------------------------------------

template<typename T>
ostream& operator<<(ostream& s, vector<T> const& v){
  s << '(';
  FOR(i, v.size()){
    s << v[i];
    if(i != v.size()-1){ s << ' '; }
  }
  s << ')';
  return s;
}

// ------------------------------------------------------------------------------

template<typename T, typename O>
struct BIT{
  BIT(int sz) : V(sz+1){ }
  T get(int i){
    i += 1;
    T x = T();
    while(i > 0){
      x = O()(V[i], x);
      i -= (i & -i);
    }
    return x;
  }
  void set(int i, T x){
    i += 1;
    while(i<V.size()){
      V[i] = O()(V[i], x);
      i += (i & -i);
    }
  }
  vector<T> V;
};

template<typename T, typename O>
ostream& operator<<(ostream& s, BIT<T, O> const& v){
  s << '(';
  FOR(i, v.V.size()){
    s << v.get(i);
    if(i != v.V.size()-2){ s << ' '; }
  }
  s << ')';
  return s;
}

// ------------------------------------------------------------------------------

template<typename T, typename O>
struct STree{
  STree (int sz, int mempty = T()) : S(sz), V(2*sz, E), E(mempty) {}

  void update_point(int i, T const& x){
    for(i += S; i >= 0; i >>= 1){
      V[i] = O(V[i], x);
    }
  }

  T at_range(int i, int j){
    function<T(int, int, int)> f = [&](int n, int a, int b){
      if (a > b || a > j || b < i) return E;
      if (a >= i && b <= j) return V[n];
      return O()(f(2*n, a, (a+b)/2), f(2*n+1, (a+b)/2+1, b));
    };
    return f(1, 0, S-1);
  }

  T const& at(int i){
    return V[S+i];
  }

  int S;
  vector<T> V;
  T E;
};

template<typename T, typename O>
ostream& operator<<(ostream& s, STree<T, O> const& v){
  vector<bool> S;
  function<void(int)> f = [&](int j){
    if(j < 2*v.S){
      FOR(i, (lli) S.size()){
        if(i == (lli) S.size()-1) s << "+ ";
        else if (S[i])      s << "| ";
        else                s << "  ";
      } s << v.V[j] << '\n';
      S.push_back(true);
      f(2*j);
      S.pop_back();
      S.push_back(false);
      f(2*j+1);
      S.pop_back();
    }
  };
  f(1);
  return s;
}

// ------------------------------------------------------------------------------

template<typename A, typename B>
ostream& operator<<(ostream& s, tuple<A, B> const& a){
  return s << '(' << X(a) << ", " << Y(a) << ')';
}

template<typename A, typename B, typename C>
ostream& operator<<(ostream& s, tuple<A, B, C> const& a){
  return s << '(' << X(a) << ", " << Y(a) << ", " << Z(a) << ')';
}

template<typename A, typename B>
tuple<A, B> operator+(tuple<A, B> const& a, tuple<A, B> const& b){
  return make_tuple(X(a)+X(b), Y(a)+Y(b));
}

template<typename A, typename B, typename C>
tuple<A, B, C> operator+(tuple<A, B, C> const& a, tuple<A, B, C> const& b){
  return make_tuple(X(a)+X(b), Y(a)+Y(b), Z(a)+Z(b));
}

template<typename A, typename B>
tuple<A, B> operator-(tuple<A, B> const& a, tuple<A, B> const& b){
  return make_tuple(X(a)-X(b), Y(a)-Y(b));
}

template<typename A, typename B, typename C>
tuple<A, B, C> operator-(tuple<A, B, C> const& a, tuple<A, B, C> const& b){
  return make_tuple(X(a)-X(b), Y(a)-Y(b), Z(a)-Z(b));
}

template<typename A>
A dot(tuple<A, A> const& a, tuple<A, A> const& b){
  return X(a)*X(b) + Y(a)*Y(b);
}

template<typename A>
A det(tuple<A, A> const& a, tuple<A, A> const& b){
  return X(a)*Y(b) - Y(a)*X(b);
}

template<typename A>
A dot(tuple<A, A, A> const& a, tuple<A, A, A> const& b){
  return X(a)*X(b) + Y(a)*Y(b) + Z(a)*Z(b);
}

template<typename A>
A det(tuple<A, A, A> const& a, tuple<A, A, A> const& b, tuple<A, A, A> const& c){
  return X(a)*(Y(b)*Z(c)-Z(b)*Y(c))-Y(a)*(X(b)*Z(c)-Z(b)*X(c))+Z(a)*(X(b)*Y(c)-Y(b)*X(c));
}

// ------------------------------------------------------------------------------

lli solve(lli a, lli b, lli l){
  lli s = 0;
  FOR(x, l+1){
    s += (x+1) * max<lli>(0, (l-x+1) - max<lli>(0, b+x-a));
  }
  return s;
}

int main(int, char**){
  ios::sync_with_stdio(false);
  lli a, b, c, l; cin >> a >> b >> c >> l;
  cout << ((l+1)*(l+2)*(l+3))/6 - solve(a, b+c, l) - solve(b, a+c, l) - solve(c, a+b, l) << endl;
  return 0;
}