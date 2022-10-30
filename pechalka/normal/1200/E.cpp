#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>

using namespace std;

const long long BASE = 567;
const long long MOD = 1e9  + 447;

const long long MAXLEN = 1e6;
long long BASEPOW[MAXLEN + 1];

long long gethash(vector<long long> &hashs, int l, int r){
  return ((hashs[r] - hashs[l] * BASEPOW[r - l]) % MOD + MOD) % MOD;
}

int main(){
  BASEPOW[0] = 1;
  for (int i = 1; i <= MAXLEN; ++i)
    BASEPOW[i] = (BASEPOW[i - 1] * BASE) % MOD;
  int n;
  cin >> n;
  vector<string> S(n);
  vector<vector<long long>> hashs(n);
  for (int i = 0; i < n; ++i){
    cin >> S[i];
    hashs[i].resize(S[i].size() + 1);
    for (int j = 0; j < S[i].size(); ++j)
      hashs[i][j + 1] = (hashs[i][j] * BASE + S[i][j]) % MOD;
  }
  string now = S[0];
  vector<long long> nowhash = hashs[0];
  for (int i = 1; i < n; ++i){
    int samelen = 0;
    for (int len = 1; len <= min(now.size(), S[i].size()); ++len) {
      if (gethash(nowhash, now.size() - len, now.size()) == gethash(hashs[i], 0, len))
        samelen = len;
    }
    for (int j = samelen; j < S[i].size(); ++j){
      now += S[i][j];
      nowhash.push_back((nowhash.back() * BASE + S[i][j]) % MOD);
    }
  }
  cout << now;
  return 0;
}