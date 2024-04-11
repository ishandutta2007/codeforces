//#define NDEBUG

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

namespace n91 {

using i32 = std::int32_t;
using i64 = std::int64_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using isize = std::ptrdiff_t;
using usize = std::size_t;

struct rep {
  struct itr {
    usize i;
    constexpr itr(const usize i) noexcept : i(i) {}
    void operator++() noexcept { ++i; }
    constexpr usize operator*() const noexcept { return i; }
    constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
  };
  const itr f, l;
  constexpr rep(const usize f, const usize l) noexcept
      : f(std::min(f, l)), l(l) {}
  constexpr auto begin() const noexcept { return f; }
  constexpr auto end() const noexcept { return l; }
};
struct revrep {
  struct itr {
    usize i;
    constexpr itr(const usize i) noexcept : i(i) {}
    void operator++() noexcept { --i; }
    constexpr usize operator*() const noexcept { return i; }
    constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
  };
  const itr f, l;
  constexpr revrep(const usize f, const usize l) noexcept
      : f(l - 1), l(std::min(f, l) - 1) {}
  constexpr auto begin() const noexcept { return f; }
  constexpr auto end() const noexcept { return l; }
};
template <class T> auto md_vec(const usize n, const T &value) {
  return std::vector<T>(n, value);
}
template <class... Args> auto md_vec(const usize n, Args... args) {
  return std::vector<decltype(md_vec(args...))>(n, md_vec(args...));
}
template <class T> constexpr T difference(const T &a, const T &b) noexcept {
  return a < b ? b - a : a - b;
}
template <class T> void chmin(T &a, const T &b) noexcept {
  if (b < a)
    a = b;
}
template <class T> void chmax(T &a, const T &b) noexcept {
  if (a < b)
    a = b;
}
template <class F> class rec_lambda {
  F f;

public:
  rec_lambda(F &&f_) : f(std::forward<F>(f_)) {}
  template <class... Args> auto operator()(Args &&... args) const {
    return f(*this, std::forward<Args>(args)...);
  }
};
template <class T> T scan() {
  T ret;
  std::cin >> ret;
  return ret;
}
constexpr char eoln = '\n';
template <class T> T ceildiv(const T &l, const T &r) {
  return l / r + (l % r != 0 ? 1 : 0);
}

} // namespace n91


#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>


#include <vector>

namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        std::vector<int> level(_n), iter(_n);
        internal::simple_queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            level[v] = _n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder


#include <limits>
#include <numeric>

namespace n91 {

void solve() {
  const usize n = scan<usize>();
  const usize m = scan<usize>();
  const usize k = scan<usize>();
  std::vector<u32> from(n, 0), to(n, 0);
  std::vector<std::pair<usize, usize>> edges(m);
  for (auto &[u, v] : edges) {
    std::cin >> u >> v;
    u -= 1;
    v -= 1;
  }

  const auto flow = [&]() -> std::pair<usize, isize> {
    atcoder::mf_graph<int> g(2 * n + 2);
    const usize s = 2 * n;
    const usize t = 2 * n + 1;
    for (const usize i : rep(0, n)) {
      g.add_edge(s, i, 1);
      g.add_edge(n + i, t, 1);
    }
    for (const auto [u, v] : edges) {
      if (!from[u] && !to[v]) {
        g.add_edge(u, n + v, 1);
      }
    }
    const usize f = g.flow(s, t);
    const auto cut = g.min_cut(s);
    isize ret = 0;
    for (const usize i : rep(0, n)) {
      if (!cut[i]) {
        ret = i + 1;
      }
      if (cut[n + i]) {
        ret = -isize(i + 1);
      }
    }
    assert(f == 0 || ret != 0);
    return {f, ret};
  };

  std::vector<isize> seq;
  while (true) {
    auto [f, b] = flow();
    if (f == 0) {
      break;
    }
    if (b > 0) {
      from[b - 1] = 1;
    } else {
      to[(-b) - 1] = 1;
    }
    seq.push_back(b);
  }
  std::vector<u64> x(k), y(k);
  for (const usize i : rep(0, k)) {
    std::cin >> x[i] >> y[i];
  }

  const auto inter =
      [&](const usize all) -> std::pair<u64, std::vector<std::vector<isize>>> {
    std::vector<std::vector<isize>> strat(k);
    struct state {
      u64 cost;
      usize wave;
      bool operator<(const state &r) const { return cost > r.cost; }
    };
    std::priority_queue<state> que;
    const auto push = [&](const usize i) {
      if (x[i] <= y[i] * strat[i].size()) {
        que.push({0, i});
      } else {
        que.push({std::min<u64>(x[i] - y[i] * strat[i].size(), y[i]), i});
      }
    };
    u64 ans = 0;
    usize stnum = 0;
    for (const usize i : rep(0, k)) {
      if (i == all) {
        ans += x[i];
        while (stnum != seq.size()) {
          strat[i].push_back(seq[stnum]);
          stnum += 1;
        }
        break;
      }
      push(i);
      while (true) {
        if (seq.size() - stnum < n - (i + 1)) {
          break;
        }
        auto [cost, wave] = que.top();
        que.pop();
        strat[wave].push_back(seq[stnum]);
        stnum += 1;
        push(wave);
        ans += cost;
      }
    }
    return {ans, strat};
  };

  u64 ans = 1e18;
  std::vector<std::vector<isize>> strat;
  for (const usize i : rep(0, k + 1)) {
    auto [aa, ss] = inter(i);
    if (ans > aa) {
      ans = aa;
      strat = ss;
    }
  }

  usize stnum = 0;
  for (const auto &s : strat) {
    stnum += s.size() + 1;
  }

  std::cout << stnum << eoln;
  for (const usize i : rep(0, k)) {
    for (const auto b : strat[i]) {
      std::cout << b << " ";
    }
    std::cout << 0 << " \n"[i + 1 == k];
  }
}

void main_() {
  //*
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  //*/
  const usize t = 1;
  for (const usize i : rep(0, t)) {
    solve();
  }
}

} // namespace n91

int main() {
  n91::main_();
  return 0;
}