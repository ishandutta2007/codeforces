#include <bits/stdc++.h>
 
typedef uint64_t int_t;
const int_t N = 7000;
 
int_t masks[N];
int_t exps[N];
int_t n;
typedef std::map<int_t, int_t> g_t;
 
g_t g;
std::map<int_t, int_t> lones;
 
int_t solve() {
 
  std::set<int_t> notLones;
 
  for (int_t i = 0; i != n; ++i) {
    int_t mask = masks[i];
    int ex = exps[i];
    auto res = lones.insert(std::make_pair(mask, ex));
        
    if (!res.second) {
      auto gres = g.insert(std::make_pair(mask, (int_t)/*experience*/0));
      
      auto &exp = gres.first->second;
      exp += ex;
      
      notLones.insert(mask);
    }
    else {  
    }
  }
    
  for (auto nlit : notLones) {
  
    
    auto lit = lones.find(nlit);
    auto &gexp = g[nlit];
    gexp += lit->second;
    lones.erase(lit);
  }
  
  for (const auto &lit : lones) {
    int_t lonem = lit.first;
    for (g_t::iterator i = g.lower_bound(lonem); i != g.end(); ++i) {
      int_t gm = i->first;
        
      if ((gm | lonem) == gm) {
          auto &gexp = i->second;
          gexp += lit.second;
          break;
      }
    }
  }
  
  int_t total = 0;
  for (const auto &kv : g) {
    const auto &gexp = kv.second; 
    total += gexp;
  }
 
  return total;
}
 
int main() {
  std::cin >> n;
  for (unsigned i = 0; i != n; ++i) {
    std::cin >> masks[i];
  }
  for (unsigned i = 0; i != n; ++i) {
    std::cin >> exps[i];
  }
  std::cout << solve();
}