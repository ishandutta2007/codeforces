#include <bits/stdc++.h>

#define FOR(i, a, b)  for (llint i = (a); i < (b); i++)
#define FORd(i, a, b) for (llint i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << "\n"
#define _ << " _ " <<

typedef long long int llint;

using namespace std;

unordered_map <llint, llint > ma1;
unordered_map <llint, llint > ma2;
const llint BASE = 31337;
const llint BASE2 = 13337;
const llint MOD = 1e9 + 7;
const llint MOD2 = 1e9 + 9;

string asd;
llint out;
set <pair <llint, llint> > se;
void rek(llint x, llint a, llint b, string ss) {
  if (x == asd.size()) {
    se.insert({a, b});
    return;
  }
  if (asd[x] != '?') {
    rek(x + 1, (((a * BASE) % MOD) + (llint)(asd[x])) % MOD, (((b * BASE2) % MOD2) + (llint)(asd[x])) % MOD2, ss + asd[x]);
    return;
  }
  rek(x + 1, (((a * BASE) % MOD) + (llint)('a')) % MOD, (((b * BASE2) % MOD2) + (llint)('a')) % MOD2, ss + 'a');
  rek(x + 1, (((a * BASE) % MOD) + (llint)('b')) % MOD, (((b * BASE2) % MOD2) + (llint)('b')) % MOD2, ss + 'b');
  rek(x + 1, (((a * BASE) % MOD) + (llint)('c')) % MOD, (((b * BASE2) % MOD2) + (llint)('c')) % MOD2, ss + 'c');
  rek(x + 1, (((a * BASE) % MOD) + (llint)('d')) % MOD, (((b * BASE2) % MOD2) + (llint)('d')) % MOD2, ss + 'd');
  rek(x + 1, (((a * BASE) % MOD) + (llint)('e')) % MOD, (((b * BASE2) % MOD2) + (llint)('e')) % MOD2, ss + 'e');
  rek(x + 1, a, b, ss);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);

  llint n, m;
  cin >> n >> m;

  REP(i, n) {
    string s;
    cin >> s;

    llint tr = 0;
    llint tr2 = 0;
    REP(j, s.size()) {
      tr *= BASE;
      tr %= MOD;
      tr += (llint)(s[j]);
      tr %= MOD;

      tr2 *= BASE2;
      tr2 %= MOD2;
      tr2 += (llint)(s[j]);
      tr2 %= MOD2;

    }
    ma1[tr] += 1LL;
    ma2[tr2] += 1LL;
  }

  REP(i, m) {
    cin >> asd;
    out = 0;
    rek(0, 0, 0, "");
    for (auto it : se) {
      out += min(ma1[it.first], ma2[it.second]);
    }
    cout << out << "\n";
    se.clear();
  }

  return 0;
}