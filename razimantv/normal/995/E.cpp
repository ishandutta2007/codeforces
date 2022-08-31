#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>

int modpow(long long a, long long b, long long MOD) {
  long long ret = 1;
  while(b) {
    if (b&1) ret = (ret * a) % MOD;
    a = (a * a)% MOD;
    b >>= 1;
  }
  return ret;
}

std::map<int, std::tuple<int, int, int>> par[2];

std::vector<int> getpath(int node) {
  std::vector<int> ret;
  for (int Q = 0; Q < 2; ++Q) {
    int temp = node;
    while(std::get<1>(par[Q][temp])!=-1) {
      ret.push_back(std::get<1>(par[Q][temp]));
      temp = std::get<2>(par[Q][temp]);
    }
    if(Q == 0) std::reverse(ret.begin(), ret.end());
  }
  return ret;
}

int main() {
  int u, v, p;
  std::cin >> u >> v >> p;

  if(u ==v) {
    std::cout << 0 << std::endl;
    return 0;
  }

  par[0][u] = {0, -1, -1};
  par[1][v] = {0, -1, -1};
  std::queue<int> bfsq[2];
  bfsq[0].push(u);
  bfsq[1].push(v);

  int link;
  for (int L = 0; ; ++L) {
    for (int Q = 0; Q < 2; ++Q) {
      while (!bfsq[Q].empty()) {
        int uu = bfsq[Q].front();
        if (std::get<0>(par[Q][uu]) > L) break;
        bfsq[Q].pop();

        int next[3] = {(uu + 1) % p, (uu + p - 1) % p, modpow(uu, p - 2, p)};
        int op[3] = {1 + Q, 2 - Q, 3};
        for (int i = 0; i < 3; ++i) {
          if (!par[Q].count(next[i])) {
            par[Q][next[i]] = {L + 1, op[i], uu};
            if (par[1 - Q].count(next[i])) {
              link = next[i];
              goto BPP;
            }
            bfsq[Q].push(next[i]);
          }
        }
      }
    }
  }
BPP:
  auto answer = getpath(link);
  std::cout << answer.size() << std::endl;
  std::copy(answer.begin(), answer.end(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  return 0;
}