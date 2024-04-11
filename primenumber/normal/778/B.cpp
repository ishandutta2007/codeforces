#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

bool is_binary(const string& str) {
  for (auto&&e:str) {
    if (e < '0' || e > '1') return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  map<string, bitset<1000>> one, zero;
  bitset<1000> all_one, all_zero;
  all_one.set();
  auto get_val = [&] (const string& name, bool is_one) {
    if (name == "?") {
      return is_one ? all_one : all_zero;
    } else {
      return is_one ? one[name] : zero[name];
    }
  };
  REP(i,n) {
    string name, assign, first;
    cin>>name>>assign>>first;
    if (is_binary(first)) {
      bitset<1000> bits(first);
      one[name] = bits;
      zero[name] = bits;
    } else {
      string op, second;
      cin>>op>>second;
      auto first_one = get_val(first, true);
      auto first_zero = get_val(first, false);
      auto second_one = get_val(second, true);
      auto second_zero = get_val(second, false);
      if (op == "AND") {
        one[name] = first_one & second_one;
        zero[name] = first_zero & second_zero;
      } else if (op == "OR") {
        one[name] = first_one | second_one;
        zero[name] = first_zero | second_zero;
      } else {
        one[name] = first_one ^ second_one;
        zero[name] = first_zero ^ second_zero;
      }
    }
  }
  bitset<1000> ans_max, ans_min;
  REP(i,m) {
    int one_sum = 0;
    for (auto&&[name, val] : one) {
      if (val.test(i)) ++one_sum;
    }
    int zero_sum = 0;
    for (auto&&[name, val] : zero) {
      if (val.test(i)) ++zero_sum;
    }
    if (one_sum > zero_sum) {
      ans_max.set(i);
    }
    if (one_sum < zero_sum) {
      ans_min.set(i);
    }
  }
  cout<<ans_min.to_string().substr(1000-m)<<endl;
  cout<<ans_max.to_string().substr(1000-m)<<endl;
  return 0;
}