#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using lll = __int128_t;

std::istream &operator>>(std::istream &is, lll &x) {
  long long tmp;
  is >> tmp;
  x = tmp;
  return is;
}

std::ostream &operator<<(std::ostream &os, const lll x) {
  //assert(x >= 0);
  return os << (long long)x;
}

lll mod(lll x, lll m) {
  return (x % m + m) % m;
}

int main() {
  std::cin.tie(0)->sync_with_stdio(0);

  std::vector<lll> offsets(100);
  std::vector<lll> v0(101);

  {
    lll v = 1;
    for (int i = 0; i <= 100; ++i, v *= 2)
      v0[i] = v;
  }

  int q;
  std::cin >> q;
  for (int qq = 0; qq < q; ++qq) {
    int t;
    std::cin >> t;

    //std::cerr << "t = " << t << '\n';

    if (t == 2) {
      lll x, k;
      std::cin >> x >> k;

      for (int i = 0; i < 100; ++i) {
        if (v0[i+1] <= x) continue;
        offsets[i] -= k;
        offsets[i] %= v0[i];
        if (offsets[i] < 0) offsets[i] += v0[i];
        k *= 2;
      }

    } else if (t == 1) {
      lll x, k;
      std::cin >> x >> k;
      
      for (int i = 0; i < 100; ++i) {
        if (v0[i+1] <= x) continue;
        offsets[i] -= k;
        offsets[i] %= v0[i];
        if (offsets[i] < 0) offsets[i] += v0[i];
        break;
      }

    } else if (t == 3) {
      lll x;
      std::cin >> x;

      //std::cerr << x << '\n';

      int i;
      for (i = 0; v0[i+1] <= x; ++i);
        //std::cerr << i << ' ' << v0[i+1] << ' ' << x << '\n';


      lll p = x-v0[i]-offsets[i];
      p %= v0[i];
      if (p < 0) p += v0[i];

      //std::cerr << p << '\n';

      while (i >= 0) {
        std::cout << v0[i] + mod(p+offsets[i], v0[i]) << ' ';
        p /= 2;
        --i;
      }

      std::cout << '\n';


    } else assert(0);

    /*
    for (int i = 0; i < 4; ++i)
      std::cerr << offsets[i] << ' ';
    std::cerr << '\n';
    // */
  }
}