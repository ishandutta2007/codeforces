#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  
  const auto Query = [&](vector<int> S) {
    cout << "? " << S.size();
    for (auto s : S) cout << ' ' << s;
    cout << endl;
    string x;
    cin >> x;
    return x == "YES";
  };
  const auto Answer = [&](int x) {
    cout << "! " << x << endl;
    string ret;
    cin >> ret;
    if (ret == ":)") exit(0);    
  };
  vector<int> S;
  for (int i = 1; i <= n; i++) S.emplace_back(i);
  while (S.size() >= 4) {
    int cur = 0;
    vector<int> A, B;
    for (auto s : S) {
      if (cur == 0) {
        A.emplace_back(s);
      } else if (cur == 1) {
        B.emplace_back(s);
      } else if (cur == 2) {
        A.emplace_back(s);
        B.emplace_back(s);
      }
      cur += 1;
      cur %= 4;
    }
    int qA = Query(A);
    int qB = Query(B);
    vector<int> newS;
    if (qA == 0 && qB == 0) {
      // TT: not A and not B
      // TF: not A and B
      // FT: A and not B
      for (auto s : S) {
        bool inA = binary_search(begin(A), end(A), s);
        bool inB = binary_search(begin(B), end(B), s);
        if ((inA && !inB) || (!inA && inB) || (!inA && !inB)) {
          newS.emplace_back(s);
        }
      }
    } else if (qA == 0 && qB == 1) {
      // TT: not A and B
      // TF: not A and not B
      // FT: A and B
      for (auto s : S) {
        bool inA = binary_search(begin(A), end(A), s);
        bool inB = binary_search(begin(B), end(B), s);
        if ((!inA && inB) || (!inA && !inB) || (inA && inB)) {
          newS.emplace_back(s);
        }
      }
    } else if (qA == 1 && qB == 0) {
      // TT: A and not B
      // TF: A and B
      // FT: not A and not B
      for (auto s : S) {
        bool inA = binary_search(begin(A), end(A), s);
        bool inB = binary_search(begin(B), end(B), s);
        if ((inA && !inB) || (inA && inB) || (!inA && !inB)) {
          newS.emplace_back(s);
        }
      }
    } else if (qA == 1 && qB == 1) {
      // TT: A and B
      // TF: A and not B
      // FT: not A and B
      for (auto s : S) {
        bool inA = binary_search(begin(A), end(A), s);
        bool inB = binary_search(begin(B), end(B), s);
        if ((inA && inB) || (inA && !inB) || (!inA && inB)) {
          newS.emplace_back(s);
        }
      }
    }
    // |newS| = 3/4 |S|
    assert(newS.size() < S.size());
    S = newS;
  }
  
  
  if (S.size() == 3) {
    if (Query({S[0]})) {
      // Claim: 1
      if (Query({S[0], S[1]})) {
        // Claim: 1 or 2
        // Possible: 1 or 2
        Answer(S[0]);
        Answer(S[1]);
      } else {
        // Claim: 3
        Answer(S[0]);
        Answer(S[2]);
      }
    } else {
      // Claim: 2 or 3
      if (Query({S[0], S[1]})) {
        // Claim: 1 or 2
        if (Query({S[2]})) {
          // Claim: 3
          // TTT: Impos
          // TTF: 2
          // TFT: 3
          // FTT: Impos
          // FTF: 1
          Answer(S[2]);
          // Not 3
          // So last must be False
          if (Query({S[0]})) {
            Answer(S[0]);
          } else {
            Answer(S[1]);
          }
        } else {
          // Claim: 1 or 2
          // TTT: 2
          // TTF: Impos
          // TFT: Impos
          // FTT: 1
          // FTF: Impos
          Answer(S[0]);
          Answer(S[1]); 
        }
      } else {
        // Claim: 3
        Answer(S[1]);
        Answer(S[2]);
      }
    }
  } else {
    for (auto s : S) {
      Answer(s);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
}