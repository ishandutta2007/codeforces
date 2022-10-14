#include <bits/stdc++.h>
using namespace std;

using lint = long long;
// #define int lint

lint ReadInt() {
  char c = getchar();
  while (!('0' <= c && c <= '9')) c = getchar();
  lint x = 0;
  while ('0' <= c && c <= '9') {
    x = x * 10 + (c - '0');
    c = getchar();
  }
  return x;
}

void Main() {
  lint X, Y;
  cin >> X >> Y;
  // lint N = Y % X + X;
  // cout << N << '\n';

  // for (N = 1; N <= Y; N++) {
  //   if (N % X == Y % N) {
  //     cout << N << ' ';
  //   }
  // }
  // cout << '\n';
  // return;
  const int MAX = 1e4;
  // lint mx = 0;
  // for (X = 1; X <= MAX; X++) for (Y = 1; Y <= MAX; Y++) 
  {
    // if (X & 1) continue;
    // if (Y & 1) continue;
    lint N;
    if (X > Y) {
      N = X + Y;
    } else if (X == Y) {
      N = X;
    } else if (Y % X == 0) {
      N = X;
    } else {
      // lint b = (Y % X) / 2;
      // N = aX + b
      // Y = N + b
      for (lint b : {(Y % X)/2, (X + (Y % X))/2}) {
        N = Y - b;
        if (N % X == Y % N) {
          break;
        }
      }
      // b = 1, 3
      // N = 5, 2
      // 
      // N = Y - 
      // 2b < X: 2b = Y mod X
      // 2b >= X: 2b - X = Y mod X
      // b = (X + Y)/2
      // 
      //
      // N = Y - b
      // 
      // Y - N = N - aX
      // 
      // 
      // int ok = 0;
      // for (lint cand : {(X + Y) / 2, Y - 1, X / 2 + Y, X + Y/2, X - 1 + Y/2, X + 1 + Y/2, X/2 + Y - 1, X/2 + Y + 1}) {
      //   N = cand;
      //   if (N % X == Y % N) {
      //     ok = 1;
      //     break;
      //   }
      // }
      // lint s = X + Y;
      // while (s > 0) {
      //   if (s % X == Y % s) {
      //     N = s;
      //     ok =1;
      //     break;
      //   }
      //   if (s & 1) break;
      //   s /= 2;
      // }
      // lint g = gcd(X, Y);
      // lint b = 1;
      // while (true) {
      //   N = (X + Y) / b;
      //   if (N == 0) break;
      //   if (N % X == Y % N) break;
      //   b *= 2;
      // }
      // // while (g % 2 == 0) g /= 2;

      // if (N == 0 || N % X != Y % N) {
      //   N = Y;
      //   while (N % X != Y % N) N -= 1;
      //   cout << X << ' ' << Y << ' ' << N << '\n';
      //   continue;
      // }
      // lint N1 = N, N2 = N;
      // while (true) {
      //   if (N1 % X == Y % N1) {
      //     N = N1;
      //     break;
      //   }
      //   if (N2 % X == Y % N2) {
      //     N = N2;
      //     break;
      //   }
      //   N1
        
      // }
      // while (gcd(N, X) != 1) N -= 1;

      // mx = max(mx, Y - N);
      // cout << X << ' ' << Y << ' ' << N << '\n';
      // X < Y
      // N = aX + b
      // Y = cN + b
      // Y = caX + bc + b
      // N - aX = Y - cN
      // (c + 1)N = Y + aX
      // N = (Y + aX)/(c + 1) = aX + b
      // 
      // X < N < Y

      // N = (caX + bc + b + aX)/(c + 1)

      // c = 1:
      // Y = N + b
      // N = aX + b
      // Y = aX + 2b
      // Y mod X = 2b
      // 
      // N = (2aX + 3b)/2
      // N = aX + 3b/2

      // N = ((c + 1)(aX + b))/(c + 1)
      // 
      // Y = cax
      // N - (N/X)*X = b
      // 
      // N + Y = aX + cN + 2b
      // Case: N < X
      // then N = Y mod N
      // (Y - X) = 0 mod N
      // 
      // (1 - c)N + Y - aX = 2b
      // 
      // Y - aX = 2b mod N
      // Y = caX + cb + b
      // Y mod X = b(c + 1) mod X
      // Y mod X != 0
      // so Y mod X = 2k for some k < X/2
      // 2k = b(c + 1) mod X
      // 
      // b < X and b < N
      // 
      // 
      // lint b = Y % X;
      // lint ca = (Y - b) / X;
      // (Y - b)/c = aX + b
      // N = aX + Y - cN
      // (c + 1)N = aX + Y
      // N = (aX + Y)/(c + 1)
      // c = (Y - b)/N
      // N = (aX + Y)/((Y - b + N)/N)
      // Y - b + N = ax + Y
      // Y  - b = acX + cb
      // Y = acX + 2b
      // 
      // cout << X << ' ' << Y << '\n';
      // cout << ca << ' ' << b << '\n';
      // return;
    }
    // lint N = Y % X + 1e9 * X;
    // // X = 4 Y = 6
    // // 
    // if (Y % X == 0) N = Y;
    if(N % X != Y % N) {
      assert(false);
      // cout << "WA\n";
      // cout << X << ' ' << Y << ' ' << N << '\n';
      return;
    }
    cout <<  N << '\n';
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}