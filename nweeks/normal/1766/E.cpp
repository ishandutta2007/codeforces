#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXP = 20;
const int MAXN = 3e5 + 1;
const int MAXK = 40;
short jmp[MAXP][MAXN][MAXK];

vector<vector<int>> possibles;

int getId(vector<int> &vec) {
  return lower_bound(possibles.begin(), possibles.end(), vec) -
         possibles.begin();
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int len;
  cin >> len;
  vector<int> arr(len);
  for (int &x : arr)
    cin >> x;

  possibles.push_back({});
  for (int i = 1; i <= 3; ++i)
    possibles.push_back({i});
  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 3; ++j)
      possibles.push_back({i, j});
  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 3; ++j)
      for (int k = 1; k <= 3; ++k)
        possibles.push_back({i, j, k});

  sort(possibles.begin(), possibles.end());

  ll sol = 0;
  for (int i = 0; i < len; ++i)
    if (!arr[i])
      sol += (i + 1LL) * (len - i);
  int nbPossible = possibles.size();

  for (int i = 0; i < len; ++i) {
    for (int bef = 0; bef < nbPossible; ++bef) {
      if (!arr[i]) {
        jmp[0][i][bef] = bef;
        continue;
      }
      vector<int> vec = possibles[bef];
      bool found = false;
      for (int &x : vec)
        if (x & arr[i]) {
          x = arr[i];
          found = true;
          break;
        }
      if (!found)
        vec.push_back(arr[i]);
      if (vec.size() > 3)
        jmp[0][i][bef] = -1;
      else
        jmp[0][i][bef] = getId(vec);
    }
  }
  for (int p = 0; p < MAXP - 1; ++p)
    for (int i = 0; i < len; ++i)
      for (int bef = 0; bef < nbPossible; ++bef) {
        if (i + (1 << p) >= len) {
          jmp[p + 1][i][bef] = -1;
        } else {
          int x = jmp[p][i][bef];
          if (x == -1)
            jmp[p + 1][i][bef] = -1;
          else {
            jmp[p + 1][i][bef] = jmp[p][i + (1 << p)][x];
            assert(-1 <= jmp[p + 1][i][bef] and MAXK > jmp[p + 1][i][bef]);
          }
        }
      }

  for (int deb = 0; deb < len; ++deb) {
    int curPos = deb;
    vector<int> vec;
    int start = getId(vec);
    int bef = curPos;
    while (curPos <= len) {
      if (curPos == len) {
        sol += (curPos - bef) * possibles[start].size();
        break;
      }
      for (int p = MAXP - 1; p >= 0; --p) {
        if (jmp[p][curPos][start] >= 0 and
            possibles[jmp[p][curPos][start]].size() ==
                possibles[start].size()) {
          start = jmp[p][curPos][start];
          curPos += 1 << p;
        }
      }
      sol += (curPos - bef) * (ll)possibles[start].size();
      if (curPos == len)
        break;
      start = jmp[0][curPos][start];
      assert(start != -1);
      bef = curPos++;
    }
  }
  cout << sol << endl;
}