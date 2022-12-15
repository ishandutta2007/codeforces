#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> swaps;
int lenArray, nbSwaps;

void test(int curSwap, int maskSeen, int maskVal) {
  if (curSwap == nbSwaps) {
    for (int i = 0; i < lenArray; ++i)
      if (!((1LL << i) & maskSeen)) {
        cout << "REJECTED";
        cout << endl;
        exit(0);
      }
    bool seen1 = false;
    for (int i = 0; i < lenArray; ++i) {
      if ((1LL << i) & maskVal)
        seen1 = true;
      else if (seen1) {
        cout << "REJECTED";
        cout << endl;
        exit(0);
      }
    }
    return;
  }

  int cntUnset = __builtin_popcountll(~maskSeen & swaps[curSwap]);
  int cnt1 = __builtin_popcountll(maskVal & swaps[curSwap]);
  int cnt0 = __builtin_popcountll(swaps[curSwap]) - cnt1 - cntUnset;
  int nxtVal = maskVal | swaps[curSwap];
  int nxtSeen = maskSeen | swaps[curSwap];

  int cur = 0;
  int nbVus = 0;
  while (nbVus < cnt0) {
    if ((1LL << cur) & swaps[curSwap]) {
      nbVus++;
      nxtVal ^= 1LL << cur;
    }
    ++cur;
  }

  for (int add0 = 0; add0 <= cntUnset; ++add0) {
    assert(__builtin_popcountll(nxtVal & swaps[curSwap]) ==
           __builtin_popcountll(swaps[curSwap]) - cnt0 - add0);
    test(curSwap + 1, nxtSeen, nxtVal);
    if (add0 < cntUnset) {
      while (!((1LL << cur) & swaps[curSwap]))
        ++cur;
      assert(cur < lenArray);
      nxtVal -= 1LL << cur++;
    }
  }
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> lenArray >> nbSwaps;
  if (lenArray == 1) {
    cout << "ACCEPTED\n";
    return 0;
  }
  swaps.resize(nbSwaps);
  for (int i = 0; i < nbSwaps; ++i) {
    int l;
    cin >> l;
    for (int j = 0; j < l; ++j) {
      int x;
      cin >> x;
      swaps[i] |= 1LL << (x - 1);
    }
  }

  test(0, 0, 0);
  cout << "ACCEPTED\n";
}