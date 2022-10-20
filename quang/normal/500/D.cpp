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


#define Task "D"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;

int n;
vector <pair<int, int > > a[N];
long long ds[N], cost[N];
int sl[N];

void DFS(int u, int p) {
  sl[u] = 1;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i].first;
    if (v != p) {
      DFS(v, u);
      sl[u] += sl[v];
      ds[a[u][i].second] = 1ll * sl[v] * (n - sl[v]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
 // fi, fo;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, l;
    cin >> u >> v >> l;
    a[u].push_back(make_pair(v, i));
    a[v].push_back(make_pair(u, i));
    cost[i] = l;
  }
  DFS(1, 0);
  int q;
  long long sum = 0;
  for (int i = 1; i < n; i++)
    sum += cost[i] * ds[i];
  double sochia = (double)n * (n - 1) / 6.0;
  cin >> q;
  while(q--) {
    int r;
    long long w;
    cin >> r >> w;
    long long delta = cost[r] - w;
    sum -= delta * ds[r];
    printf("%0.6f\n", (double)sum / sochia);
    cost[r] = w;
  }
  return 0;
}