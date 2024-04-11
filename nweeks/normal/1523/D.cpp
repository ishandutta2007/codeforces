#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int nbJoueurs, nbMonnaies, maxTaille;
vector<int> masques;

int solve(int pick) {
  vector<int> newMask(nbJoueurs);
  vector<int> pos;
  for (int i(0); i < nbMonnaies; ++i)
    if ((1LL << i) & masques[pick])
      pos.push_back(i);
  int m = pos.size();
  assert(m <= maxTaille);
  for (int i(0); i < nbJoueurs; ++i)
    for (int bit(0); bit < m; ++bit)
      if ((1LL << pos[bit]) & masques[i])
        newMask[i] |= 1LL << bit;

  int maxMasque = 1LL << m;
  vector<int> cntWith(maxMasque);
  for (auto v : newMask)
    cntWith[maxMasque - 1 - v]++;

  for (int bit(0); bit < m; ++bit)
    for (int i(0); i < maxMasque; ++i)
      if ((1LL << bit) & i)
        cntWith[i] += cntWith[i - (1LL << bit)];
  int sol = 0;
  for (int i(0); i < maxMasque; ++i)
    if (2 * cntWith[i] >= nbJoueurs) {
      int rev = maxMasque - 1 - i;
      if (__builtin_popcountll(rev) > __builtin_popcountll(sol))
        sol = rev;
    }
  int c = 0;
  for (auto v : newMask)
    c += sol == (v & sol);
  assert(2 * c >= nbJoueurs);
  int ret = 0;
  for (int i(0); i < m; ++i)
    if ((1LL << i) & sol)
      ret |= 1LL << pos[i];
  return ret;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int sol = 0;
  cin >> nbJoueurs >> nbMonnaies >> maxTaille;
  masques.resize(nbJoueurs);

  for (int i(0); i < nbJoueurs; ++i) {
    string s;
    cin >> s;
    for (auto c : s)
      masques[i] = 2 * masques[i] + c - '0';
  }
  vector<int> pick(nbJoueurs);
  for (int i(0); i < nbJoueurs; ++i)
    pick[i] = i;
  shuffle(pick.begin(), pick.end(), rng);

  for (int i(0); i < 60 and i < nbJoueurs; ++i) {
    int ret = solve(pick[i]);
    if (__builtin_popcountll(ret) > __builtin_popcountll(sol))
      sol = ret;
  }
  string s(nbMonnaies, '0');
  for (int i(nbMonnaies - 1); i >= 0; --i, sol /= 2)
    if (sol % 2)
      s[i] = '1';
  cout << s << endl;
}