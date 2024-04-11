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


#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 330;

int n;
int a[N], d = 0;
string b[N];
int dd[N], res[N];
vector <int> ds;

void Go(int u) {
  dd[u] = d;
  ds.push_back(u);
  for (int i = 1; i <= n; i++)
  if(b[i][u] == '1' && i != u & !dd[i])
    Go(i);
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i], b[i] = "a" + b[i];
  for (int i = 1; i <= n; i++)
  if(!dd[i]) {
    d++;
    ds.clear();
    Go(i);
    vector <int> gt;
    for (int i = 0; i < ds.size(); i++)
      gt.push_back(a[ds[i]]);
    sort(gt.begin(), gt.end());
    sort(ds.begin(), ds.end());
    for (int i = 0; i < gt.size(); i++)
      res[ds[i]] = gt[i];
  }
  for (int i = 1; i <= n; i++) cout << res[i] << " ";
  return 0;
}