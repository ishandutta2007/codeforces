#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>


#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 1010;

int n, m, vt;
int a[N], b[N], dd[N];
int res[N];

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int i = 1; i <= m; i++) {
    if(!dd[b[i]]) {
      res[++vt] = b[i];
      dd[b[i]] = 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if(!dd[i]) res[++vt] = i;
  for (int i = 1; i <= m; i++) {
    int vt;
    for (int j = 1; j <= n; j++)
    if(res[j] == b[i]) {
      vt = j;
      break;
    }
    for (int j = vt; j > 1; j--) {
      ans += a[res[j - 1]];
      res[j] =res[j - 1];
    }
    res[1] = b[i];
  }
  cout << ans;
  return 0;
}