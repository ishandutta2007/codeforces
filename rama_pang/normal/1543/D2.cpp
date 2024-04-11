#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const int DEBUG = 0;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

void Main() {
  lint N, K;
  cin >> N >> K;

  lint ANS = 3;
  // rnd() % N;

  lint B = 0;
  {
    lint n = N;
    while (n > 1) {
      n /= K;
      B += 1;
    }
    B += 2;
  }

  // (x + z) mod K = y
  // x2 := y1 - x
  // x3 := y2 - (y1 - x)
  // x3 := y2 - y1 + x
  
  lint sgn = 1;
  vector<lint> constant(B, 0);
  const auto Guess = [&](vector<lint> y) {
    // sgn * x  
    lint g = 0;
    for (int i = B - 1; i >= 0; i--) {
      lint a = sgn * y[i] + constant[i];
      a %= K;
      a += K;
      a %= K;
      g *= K;
      g += a;
    }

    cout << g << endl;
    int foo;
    if (DEBUG) {
      foo = g == ANS;
    } else {
      cin >> foo;
    }
    if (!foo) {
      ANS ^= g;
    }

    lint x = g;
    for (int i = 0; i < B; i++) {
      y[i] = x % K;
      x /= K;
    }

    sgn *= -1;
    for (int i = 0; i < B; i++) {
      constant[i] *= -1;
      constant[i] += y[i];
      constant[i] %= K;
      constant[i] += K;
      constant[i] %= K;
    }

    return foo;
  };

  for (int cand = 0; cand < N; cand++) {
    vector<lint> y(B);
    lint x = cand;
    for (int i = 0; i < B; i++) {
      y[i] = x % K;
      x /= K;
    }
    if (Guess(y)) {
      return;
    }  
  }
  // cout << ANS << endl;
  assert(false);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}

/*

11
10
11


*/