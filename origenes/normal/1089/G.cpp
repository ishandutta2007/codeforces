#include <bits/stdc++.h>

using namespace std;

int t;
int k;
int s[14];

int main() {
  cin >> t;
  for (int kase = 0; kase < t; ++kase) {
    cin >> k;
    int teach_d = 0;
    for (int i = 0; i < 7; ++i) {
      cin >> s[i];
      teach_d += s[i];
      s[i + 7] = s[i];
    }
    int wk = k / teach_d;
    int rem = k % teach_d;
    int extra_d = 7;
    if (rem == 0) {
      wk--;
      rem = teach_d;
    }
//    cout << k << endl;
//    cout << teach_d << endl;
//    cout << wk << endl;
    int cnt = 0;
    int left = find(s, s + 14, 1) - s;
    for (int right = left; right < 14; ++right) {
      cnt += s[right];
      if (cnt == rem) {
        extra_d = min(extra_d, right - left + 1);
        left = find(s + left + 1, s + 14, 1) - s;
        cnt--;
      }
    }

    cout << wk * 7 + extra_d << endl;
  }

  return 0;
}

/*
3
2
0 1 0 0 0 0 0
100000000
1 0 0 0 1 0 1
1
1 0 0 0 0 0 0
 */