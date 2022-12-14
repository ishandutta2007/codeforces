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

class TaskD {
 public:
  void solveOne(istream &in, ostream &out) {
    int n;
    in >> n;
    vector<set<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
      int a;
      int b;
      in >> a >> b;
      --a; --b;
      adj[a].insert(b);
      adj[b].insert(a);
    }
    vector<bool> alive(n, true);
    while (true) {
      int a = -1;
      int b = -1;
      for (int i = 0; i < n; ++i) if (adj[i].size() <= 1 && alive[i]) {
        if (a < 0) {
          a = i;
        } else if (b < 0) {
          b = i;
        }
      }
      assert(a >= 0);
      if (b < 0) {
        out << "! " << (a + 1) << "\n";
        out.flush();
        return;
      }
      out << "? " << (a + 1) << " " << (b + 1) << "\n";
      out.flush();
      int w;
      in >> w;
      --w;
      if (w == a) {
        out << "! " << (a + 1) << "\n";
        out.flush();
        return;
      }
      if (w == b) {
        out << "! " << (b + 1) << "\n";
        out.flush();
        return;
      }
      alive[a] = false;
      alive[b] = false;
      int aa = *adj[a].begin();
      int bb = *adj[b].begin();
      adj[aa].erase(a);
      adj[a].erase(aa);
      adj[bb].erase(b);
      adj[b].erase(bb);
    }
  }

  void solve(std::istream &in, std::ostream &out) {
    int nt;
    nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne(in, out);
    }
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TaskD solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}