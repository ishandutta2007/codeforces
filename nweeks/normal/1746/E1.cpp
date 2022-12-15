#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int lb, int ub) {
  return uniform_int_distribution<int>(lb, ub)(rng);
}
int X;
int Q;

bool make_query(vector<int> vec) {
  ++Q;
  assert(Q <= 82);
  /*for (int x : vec)
    if (x == X)
      return true;
  return false;*/
  cout << "? " << vec.size();
  for (int x : vec)
    cout << ' ' << x;
  cout << endl;
  string s;
  cin >> s;
  return s == "YES";
}

void make_guess(int x) {
  /*if (x == X)
    exit(0);
  return;*/
  cout << "! " << x << endl;
  string s;
  cin >> s;
  if (s == ":)")
    exit(0);
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  // X = randint(1, 1e5);
  cin >> n;

  vector<int> poss(n);
  iota(poss.begin(), poss.end(), 1);

  while (poss.size() > 3) {
    array<vector<int>, 4> parties;
    parties.fill(vector<int>());
    for (int i = 0; i < (int)poss.size(); ++i)
      parties[i % 4].push_back(poss[i]);
    vector<int> A, B;
    for (int x : parties[0])
      A.push_back(x), B.push_back(x);
    for (int x : parties[1])
      A.push_back(x);
    for (int x : parties[2])
      B.push_back(x);
    bool b1 = make_query(A), b2 = make_query(B);
    int toRem = -1;
    if (b1 and b2)
      toRem = 3;
    else if (!b1 and !b2)
      toRem = 0;
    else if (b1 and !b2)
      toRem = 2;
    else
      toRem = 1;
    poss.clear();
    for (int i = 0; i < 4; ++i)
      if (i != toRem)
        for (int x : parties[i])
          poss.push_back(x);
  }
  if (poss.size() == 1)
    make_guess(poss[0]);
  else if (poss.size() == 2)
    make_guess(poss[0]), make_guess(poss[1]);
  vector<bool> sol(6);
  for (int i = 0; i < 6; ++i)
    sol[i] = make_query({poss[i / 2]});
  for (int i = 0; i < 3; ++i)
    if (sol[2 * i] == sol[2 * i + 1]) {
      if (sol[2 * i])
        make_guess(poss[i]);
      for (int j = 0; j < 3; ++j)
        if (j != i)
          make_guess(poss[j]);
    }
  make_guess(poss[1]);
  if (sol[2]) {
    if (sol[1])
      make_guess(poss[0]);
    else
      make_guess(poss[2]);
  } else {
    if (sol[4])
      make_guess(poss[2]);
    else
      make_guess(poss[0]);
  }
  assert(false);
}