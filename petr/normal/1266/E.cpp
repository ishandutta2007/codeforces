/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

class TaskE {
 public:
  void solveOne(istream &in, ostream &out) {

  }

  void solve(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    vector<int64> a(n);
    int64 total = 0;
    for (int i = 0; i < n; ++i) {
      in >> a[i];
      total += a[i];
    }
    int q;
    in >> q;
    map<pair<int, int>, int> have;
    vector<int64> countSaved(n);
    int64 totalSaved = 0;
    for (int qi = 0; qi < q; ++qi) {
      pair<int, int> key;
      in >> key.first >> key.second;
      --key.first;
      int val;
      in >> val;
      --val;
      auto it = have.find(key);
      if (it != have.end()) {
        int v = it->second;
        totalSaved -= min(countSaved[v], a[v]);
        --countSaved[v];
        totalSaved += min(countSaved[v], a[v]);
        have.erase(it);
      }
      if (val != -1) {
        have[key] = val;
        int v = val;
        totalSaved -= min(countSaved[v], a[v]);
        ++countSaved[v];
        totalSaved += min(countSaved[v], a[v]);
      }
      out << total - totalSaved << "\n";
    }
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TaskE solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}