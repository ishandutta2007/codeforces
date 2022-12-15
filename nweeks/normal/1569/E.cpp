#include <bits/stdc++.h>
#define int long long
using namespace std;

template <const int32_t MOD> struct ModInt {
  int32_t x;
  ModInt() : x(0) {}
  ModInt(long long u) : x(u % MOD) {
    x %= MOD;
    if (x < 0)
      x += MOD;
  }
  friend bool operator==(const ModInt &a, const ModInt &b) {
    return a.x == b.x;
  }
  friend bool operator!=(const ModInt &a, const ModInt &b) {
    return a.x != b.x;
  }
  friend bool operator<(const ModInt &a, const ModInt &b) { return a.x < b.x; }
  friend bool operator>(const ModInt &a, const ModInt &b) { return a.x > b.x; }
  friend bool operator<=(const ModInt &a, const ModInt &b) {
    return a.x <= b.x;
  }
  friend bool operator>=(const ModInt &a, const ModInt &b) {
    return a.x >= b.x;
  }
  static ModInt sign(long long k) {
    return ((k & 1) ? ModInt(MOD - 1) : ModInt(1));
  }

  ModInt &operator+=(const ModInt &m) {
    x += m.x;
    if (x >= MOD)
      x -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &m) {
    x -= m.x;
    if (x < 0LL)
      x += MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &m) {
    x = (1LL * x * m.x) % MOD;
    return *this;
  }

  friend ModInt operator-(const ModInt &a) {
    ModInt res(a);
    if (res.x)
      res.x = MOD - res.x;
    return res;
  }
  friend ModInt operator+(const ModInt &a, const ModInt &b) {
    return ModInt(a) += ModInt(b);
  }
  friend ModInt operator-(const ModInt &a, const ModInt &b) {
    return ModInt(a) -= ModInt(b);
  }
  friend ModInt operator*(const ModInt &a, const ModInt &b) {
    return ModInt(a) *= ModInt(b);
  }

  static long long fp(long long u, long long k) {
    long long res = 1LL;
    while (k > 0LL) {
      if (k & 1LL)
        res = (res * u) % MOD;
      u = (u * u) % MOD;
      k /= 2LL;
    }
    return res;
  }

  static constexpr int mod() { return MOD; }

  ModInt fastpow(long long k) { return ModInt(fp(x, k)); }
  ModInt inv() {
    assert(x);
    return ModInt(fp(x, MOD - 2));
  }
  ModInt &operator/=(const ModInt &m) { return *this *= ModInt(m).inv(); }
  friend ModInt operator/(const ModInt &a, const ModInt &b) {
    return ModInt(a) *= ModInt(b).inv();
  }

  friend ostream &operator<<(ostream &out, const ModInt &a) {
    return out << a.x;
  }
  friend istream &operator>>(istream &in, ModInt &a) { return in >> a.x; }
};

const int MOD = 998244353;
using Mint = ModInt<MOD>;

int nbRounds;
Mint base, hsh;
const int MAXROUNDS = 6;

int position[1 << MAXROUNDS];

struct State {
  Mint valHsh;
  int winner;

  bool operator<(State other) const {
    return make_pair(valHsh, winner) < make_pair(other.valHsh, other.winner);
  };
};

map<State, tuple<State, State, int>> pred[1 << MAXROUNDS][1 << MAXROUNDS];

vector<State> calcStates(int deb, int fin, int depth) {
  if (deb + 1 == fin)
    return {{0, deb}};

  auto lft = calcStates(deb, (deb + fin) / 2, depth + 1);
  auto rgt = calcStates((deb + fin) / 2, fin, depth + 1);

  vector<State> ret;

  for (auto [hshL, winL] : lft)
    for (auto [hshR, winR] : rgt) {
      Mint hshWinL = winR * base.fastpow(1 << (depth + 1)) + hshL + hshR;
      Mint hshWinR = winL * base.fastpow(1 << (depth + 1)) + hshL + hshR;
      ret.push_back({hshWinL, winL});
      ret.push_back({hshWinR, winR});
      pred[deb][fin][{hshWinL, winL}] =
          make_tuple(State{hshL, winL}, State{hshR, winR}, 0);
      pred[deb][fin][{hshWinR, winR}] =
          make_tuple(State{hshL, winL}, State{hshR, winR}, 1);
    }
  return ret;
}

void rebuild(int deb, int fin, Mint valHsh, int win, int depth) {
  if (deb + 1 == fin) {
    position[deb] = min(position[deb], (1LL << depth) + 1);
    return;
  }
  assert(pred[deb][fin].count({valHsh, win}));
  auto [befL, befR, side] = pred[deb][fin][{valHsh, win}];
  if (side)
    position[befL.winner] = (1 << depth) + 1;
  else
    position[befR.winner] = (1 << depth) + 1;
  rebuild(deb, (deb + fin) / 2, befL.valHsh, befL.winner, depth + 1);
  rebuild((deb + fin) / 2, fin, befR.valHsh, befR.winner, depth + 1);
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> nbRounds >> base >> hsh;
  hsh /= base;

  auto lft = calcStates(1, (1 << (nbRounds - 1)) + 1, 0);
  auto rgt = calcStates(1 + (1 << (nbRounds - 1)), (1 << nbRounds) + 1, 0);

  sort(lft.begin(), lft.end(), [&](auto l, auto r) {
    return l.valHsh + base * l.winner < r.valHsh + base * r.winner;
  });
  sort(rgt.begin(), rgt.end(), [&](auto l, auto r) {
    return l.valHsh + base * l.winner < r.valHsh + base * r.winner;
  });

  for (auto [valHsh, win] : lft) {
    Mint wanted = hsh - valHsh - win;
    int lo = 0, up = rgt.size() - 1;
    while (lo < up) {
      int mid = (lo + up) / 2;
      if (rgt[mid].valHsh + base * rgt[mid].winner < wanted)
        lo = mid + 1;
      else
        up = mid;
    }
    if (rgt[lo].valHsh + base * rgt[lo].winner == wanted) {
      position[win] = 1;
      position[rgt[lo].winner] = 2;
      rebuild(1, (1 << (nbRounds - 1)) + 1, valHsh, win, 1);
      rebuild(1 + (1 << (nbRounds - 1)), (1 << nbRounds) + 1, rgt[lo].valHsh,
              rgt[lo].winner, 1);
      for (int i = 1; i <= (1 << nbRounds); ++i)
        cout << position[i] << ' ';
      cout << endl;
      return 0;
    }
  }

  for (auto [valHsh, win] : rgt) {
    Mint wanted = hsh - valHsh - win;
    int lo = 0, up = lft.size() - 1;
    while (lo < up) {
      int mid = (lo + up) / 2;
      if (lft[mid].valHsh + base * lft[mid].winner < wanted)
        lo = mid + 1;
      else
        up = mid;
    }

    if (lft[lo].valHsh + base * lft[lo].winner == wanted) {
      position[win] = 1;
      position[lft[lo].winner] = 2;
      rebuild(1, (1 << (nbRounds - 1)) + 1, lft[lo].valHsh, lft[lo].winner, 1);
      rebuild(1 + (1 << (nbRounds - 1)), (1 << nbRounds) + 1, valHsh, win, 1);
      for (int i = 1; i <= (1 << nbRounds); ++i)
        cout << position[i] << ' ';
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}