#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <deque>
#include <tuple>

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define FORU(i, j, k) for(int i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(int i = (j); i >= (k); --i)

#define X first
#define Y second

using namespace std;

template <typename T>
void hash_combine (size_t& seed, const T& val){
  seed ^= hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}
template <typename T, typename... Ts>
void hash_combine (size_t& seed, const T& val, const Ts&... args){
  hash_combine(seed, val);
  hash_combine(seed, args...);
}
void hash_combine (size_t&){}
template <typename... Ts>
size_t hash_val (const Ts&... args){
  size_t seed = 0;
  hash_combine (seed, args...);
  return seed;
}

using pt   = pair<int, int>;
using vec2 = pair<pt, pt>;

int main(int, char**){
  ios::sync_with_stdio(false);
  string s; cin >> s;
  vector<string> r;
  FOR(i, 9){
    string a = "";
    for(char& c : s){
      if(c == '0' && a != ""){
        a += '0';
      }
      if(c != '0'){
        a += '1';
        c -= 1;
      }    }
    if(a != "") r.push_back(a);
  }
  cout << r.size() << endl;
  FOR(i, r.size()) cout << r[i] << " "; cout << endl;
  return 0;
}