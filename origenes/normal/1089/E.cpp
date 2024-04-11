#include <bits/stdc++.h>

using namespace std;

bool visited[8][8];

bool find_sol(int n, int x, int y) {
  if (visited[x][y]) {
    return false;
  }
  if (x == 0 && y == 0) {
    if (n == 0) {
      cout << "a1 ";
      return true;
    } else {
      return false;
    }
  }
  if (n <= 0) {
    return false;
  }
  visited[x][y] = true;
  for (int i = 0; i < 8; ++i) {
    if (find_sol(n - 1, i, y)) {
      cout << char(x + 'a') << y + 1 << ' ';
      return true;
    }
  }
  for (int j = 0; j < 8; ++j) {
    if (find_sol(n - 1, x, j)) {
      cout << char(x + 'a') << y + 1 << ' ';
      return true;
    }
  }
  visited[x][y] = false;
  return false;
}

int main() {
  /*for (int i = 2; i <= 63; ++i) {
    cout << "if (n == " << i << ") cout << \"";
    find_sol(i, 7, 7);
    cout << "\\n\";" << endl;
    memset(visited, 0, sizeof(visited));
  }*/
  int n;
  cin >> n;
  if (n == 2) cout << "a1 a8 h8 \n";
  if (n == 3) cout << "a1 a2 a8 h8 \n";
  if (n == 4) cout << "a1 b1 b8 a8 h8 \n";
  if (n == 5) cout << "a1 c1 c8 b8 a8 h8 \n";
  if (n == 6) cout << "a1 d1 d8 c8 b8 a8 h8 \n";
  if (n == 7) cout << "a1 e1 e8 d8 c8 b8 a8 h8 \n";
  if (n == 8) cout << "a1 f1 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 9) cout << "a1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 10) cout << "a1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 11) cout << "a1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 12) cout << "a1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 13) cout << "a1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 14) cout << "a1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 15) cout << "a1 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 16) cout << "a1 a2 f2 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 17) cout << "a1 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 18) cout << "a1 a3 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 19) cout << "a1 a4 a3 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 20) cout << "a1 a3 b3 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 21) cout << "a1 a3 c3 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 22) cout << "a1 a3 d3 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 23) cout << "a1 a3 e3 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 24) cout << "a1 a3 f3 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 25) cout << "a1 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 26) cout << "a1 a4 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 27) cout << "a1 a5 a4 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 28) cout << "a1 a4 b4 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 29) cout << "a1 a4 c4 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 30) cout << "a1 a4 d4 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 31) cout << "a1 a4 e4 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 32) cout << "a1 a4 f4 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 33) cout << "a1 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 34) cout << "a1 a5 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 35) cout << "a1 a6 a5 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 36) cout << "a1 a5 b5 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 37) cout << "a1 a5 c5 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 38) cout << "a1 a5 d5 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 39) cout << "a1 a5 e5 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 40) cout << "a1 a5 f5 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 41) cout << "a1 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 42) cout << "a1 a6 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 43) cout << "a1 a7 a6 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 44) cout << "a1 a6 b6 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 45) cout << "a1 a6 c6 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 46) cout << "a1 a6 d6 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 47) cout << "a1 a6 e6 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 48) cout << "a1 a6 f6 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 49) cout << "a1 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 50) cout << "a1 a7 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 51) cout << "a1 a7 a6 b6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 52) cout << "a1 a7 b7 b6 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 53) cout << "a1 a7 c7 c6 b6 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 54) cout << "a1 a7 d7 d6 c6 b6 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 55) cout << "a1 a7 e7 e6 d6 c6 b6 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 56) cout << "a1 a7 f7 f6 e6 d6 c6 b6 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 57) cout << "a1 a7 g7 g6 f6 e6 d6 c6 b6 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 58) cout << "a1 a7 b7 g7 g6 f6 e6 d6 c6 b6 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 59) cout << "a1 a7 c7 b7 g7 g6 f6 e6 d6 c6 b6 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 60) cout << "a1 a7 d7 c7 b7 g7 g6 f6 e6 d6 c6 b6 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 61) cout << "a1 a7 e7 d7 c7 b7 g7 g6 f6 e6 d6 c6 b6 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 62) cout << "a1 a7 f7 e7 d7 c7 b7 g7 g6 f6 e6 d6 c6 b6 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  if (n == 63) cout << "a1 a7 h7 f7 e7 d7 c7 b7 g7 g6 f6 e6 d6 c6 b6 a6 h6 h5 f5 e5 d5 c5 b5 a5 g5 g4 f4 e4 d4 c4 b4 a4 h4 h3 f3 e3 d3 c3 b3 a3 g3 g2 f2 e2 d2 c2 b2 a2 h2 h1 f1 e1 d1 c1 b1 g1 g8 f8 e8 d8 c8 b8 a8 h8 \n";
  return 0;
}