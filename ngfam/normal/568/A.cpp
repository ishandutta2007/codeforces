#include<bits/stdc++.h>

using namespace std;

int isPalin(int x){
  vector<int> digits;
  while(x > 0) digits.push_back(x % 10), x /= 10;
  for(int i = 0; i < digits.size(); ++i) if(digits[i] != digits[digits.size() - i - 1]) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  vector<bool> isPrime(3000 * 1000, true);

  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i < isPrime.size(); ++i) {
    if(isPrime[i]) {
      for(int j = i + i; j < isPrime.size(); j += i) isPrime[j] = false;
    }
  }

  vector<int> cnt(isPrime.size());
  for(int i = 2; i < isPrime.size(); ++i) cnt[i] = cnt[i - 1] + isPrime[i];

  int p, q;
  cin >> p >> q;

  int cntpr = 0, cntpl = 0, ans = -1;

  for(int i = 1; i <= 2178701; ++i) {
    cntpl += isPalin(i);
    cntpr = cnt[i];
    if(cntpr * q <= cntpl * p) {
      ans = i;
    }
  }

  cout << ans << endl;

  return 0;
}