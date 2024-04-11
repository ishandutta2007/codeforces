// Solution based on editorial at: https://codeforces.com/blog/entry/48501

#include <bits/stdc++.h>
using namespace std;

int N, A, B;
vector<int> S[3];
vector<pair<int, int>> ans;

void No() {
  cout << "NO\n";
  exit(0);
}

void Move(int st, int x) {
  if (x == 0) return;
  ans.emplace_back(st, x);
  if (st == 1 && x > A) No();
  if (st == 2 && x > B) No();
  vector<int> moved(begin(S[st]), begin(S[st]) + x);
  S[st].erase(begin(S[st]), begin(S[st]) + x);
  if (st == 1) {
    S[2].insert(begin(S[2]), begin(moved), end(moved));
  } else {
    N -= x;
  }
  for (int i = 0; i + 1 < (int) S[2].size(); i++) {
    if (S[2][i] + 1 < S[2][i + 1]) {
      No();
    }
  }
}

bool Output() {
  if (!S[1].empty()) {
    int id = find(begin(S[1]), end(S[1]), N) - begin(S[1]);
    if (id < S[1].size()) {
      int cur = id;
      while (cur > 0 && S[1][cur - 1] + 1 == S[1][cur]) {
        cur--;
      }
      if (cur > 0) {
        return false;
      }
      for (int st = 1; st <= 2; st++) {
        for (int i = 0; i <= id; i++) {
          Move(st, 1);
        }
      }
      return true;
    }
  }
  if (!S[2].empty()) {
    int id = find(begin(S[2]), end(S[2]), N) - begin(S[2]);
    if (id < S[2].size()) {
      int cur = id;
      while (cur > 0 && S[2][cur - 1] + 1 == S[2][cur]) {
        cur--;
      }
      if (cur > 0) {
        return false;
      }
      Move(2, id + 1);
      return true;
    }
  }
  No();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> A >> B;

  { // coordinate compression
    map<int, int> cmp;
    S[1].resize(N);
    for (int i = 0; i < N; i++) {
      cin >> S[1][i];
      cmp[S[1][i]] = -1;
    }
    int cnt = 0;
    for (auto &i : cmp) {
      i.second = ++cnt;
    }
    for (int i = 0; i < N; i++) {
      S[1][i] = cmp[S[1][i]];
    }
    assert(cnt == N);
  }
  
  while (N > 0) {
    if (Output()) continue;
    int id = 0;
    int mn = S[1][id], mx = S[1][id];
    vector<int> lengths = {1};
    while (id + 1 < (int) S[1].size() && S[1][id + 1] <= S[1][id] + 1) {
      id++;
      mn = min(mn, S[1][id]);
      mx = max(mx, S[1][id]);
      if (S[1][id] == mn) {
        lengths.push_back(0);
      }
      lengths.back()++;
    }
    int mxlen = *max_element(begin(lengths), end(lengths));
    int holes = (mx - mn + 1) - (id + 1);
    
    if (holes > 0) {
      Move(1, id + 1);
      continue;
    }
    if (mxlen <= A && id + 1 <= B) {
      for (auto l : lengths) {
        Move(1, l);
      }
      continue;
    }
    if (id + 1 > B) {
      if ((int) lengths.size() == 1) {
        for (auto i = 0; i < lengths[0]; i++) {
          Move(1, 1);
        }
        continue;
      }
      if ((int) lengths.size() > 2) {
        Move(1, id + 1);
        continue;
      }
    } else { // id + 1 <= B
      if ((int) lengths.size() == 1) {
        for (auto i = 0; i < lengths[0]; i++) {
          Move(1, 1);
        }
        continue;
      }
      if ((int) lengths.size() > 2) {
        No();
      }
    }
    assert(lengths.size() == 2);
    for (int x = 1; x <= lengths[0]; x++) {
      if (max(x, lengths[0] + lengths[1] - x) <= A && max(lengths[0] - x, x + lengths[1]) <= B) {
        Move(1, x);
        Move(1, lengths[0] + lengths[1] - x);
        goto CONTINUE;
      }
    }
    for (int x = 1; x <= lengths[1]; x++) {
      if (max(lengths[0] + x, lengths[1] - x) <= A && max(lengths[0] + lengths[1] - x, x) <= B) {
        Move(1, lengths[0] + x);
        Move(1, lengths[1] - x);
        goto CONTINUE;
      }
    }
    No();
    CONTINUE: continue;
  }

  cout << "YES\n";
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i.first << " " << i.second << "\n";
  }
  return 0;
}