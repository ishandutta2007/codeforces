#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> prefixFun(const string &s) {
  int len = s.size();
  vector<int> kmp(len);
  for (int i(1); i < len; ++i) {
    int j = kmp[i - 1];
    while (j and s[i] != s[j])
      j = kmp[j - 1];
    if (s[i] == s[j])
      ++j;
    kmp[i] = j;
  }
  for (auto v : kmp)
    assert(v <= 1);
  return kmp;
}

void solve() {
  string s;
  cin >> s;

  map<char, int> caracs;
  for (char c : s)
    caracs[c]++;

  vector<char> possibles;
  vector<int> nbOccs;
  for (auto [c, occ] : caracs)
    possibles.push_back(c), nbOccs.push_back(occ);

  for (int i = 0; i < (int)possibles.size(); ++i)
    if (nbOccs[i] == 1) {
      cout << possibles[i];
      nbOccs[i]--;
      for (int j = 0; j < (int)possibles.size(); ++j)
        while (nbOccs[j] > 0) {
          --nbOccs[j];
          cout << possibles[j];
        }
      cout << '\n';
      return;
    }

  if (possibles.size() == 1) {
    cout << s << '\n';
    return;
  }

  if (possibles.size() == 2) {
    string ret = "";
    if (nbOccs[0] - 2 <= nbOccs[1]) {
      ret += possibles[0];
      nbOccs[0]--;
      if (nbOccs[0])
        ret += possibles[0], nbOccs[0]--;
      while (nbOccs[1]) {
        ret += possibles[1];
        nbOccs[1]--;
        if (nbOccs[0])
          ret += possibles[0], nbOccs[0]--;
      }
      assert(!nbOccs[0]);
    } else {
      ret += possibles[0];
      nbOccs[0]--;
      while (nbOccs[1])
        nbOccs[1]--, ret += possibles[1];
      while (nbOccs[0])
        nbOccs[0]--, ret += possibles[0];
    }
    cout << ret << '\n';
    return;
  }

  // Au moins 3 carac !
  string ret = "";
  if (nbOccs[0] >= 2) {
    string restant = "";
    for (int i = 1; i < (int)possibles.size(); ++i)
      for (int j = 0; j < nbOccs[i]; ++j)
        restant += possibles[i];

    if (nbOccs[0] - 2 <= (int)restant.size()) {
      ret += possibles[0];
      ret += possibles[0];
      nbOccs[0] -= 2;
      int posRes = 0;
      while (posRes < (int)restant.size()) {
        ret += restant[posRes++];
        if (nbOccs[0])
          --nbOccs[0], ret += possibles[0];
      }
    } else if ((int)nbOccs.size() > 2) {
      ret += possibles[0];
      ret += possibles[1];
      nbOccs[0]--;
      nbOccs[1]--;
      while (nbOccs[0] > 0) {
        ret += possibles[0];
        nbOccs[0]--;
      }
      ret += possibles[2];
      nbOccs[2]--;
      for (int i = 0; i < (int)possibles.size(); ++i)
        while (nbOccs[i] > 0)
          --nbOccs[i], ret += possibles[i];
    } else {
      ret += possibles[0];
      nbOccs[0]--;
      while (nbOccs[1] > 0)
        ret += possibles[1], nbOccs[1]--;
      while (nbOccs[0] > 0)
        ret += possibles[0], nbOccs[0]--;
    }
  } else {
    ret += possibles[0];
    nbOccs[0]--;
    for (int i = 0; i < (int)nbOccs.size(); ++i)
      while (nbOccs[i] > 0) {
        --nbOccs[i];
        ret += possibles[i];
      }
  }
  cout << ret << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}