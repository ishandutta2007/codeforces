#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define pii pair <int, int>

using namespace std;

vector <string> moves;

int main() {
  ios_base::sync_with_stdio(false);

  for (char c = 'b'; c <= 'h'; c++) {
    string tr = "";
    tr.push_back(c);
    tr += "1";
    moves.push_back(tr);
  }

  for (char c = '2'; c <= '7'; c++) {
    string tr = "h";
    tr.push_back(c);
    moves.push_back(tr);    
  }
  
  for (char c = '7'; c >= '2'; c--) {
    string tr = "g";
    tr.push_back(c);
    moves.push_back(tr);    
  }

  for (char c = '2'; c <= '7'; c++) {
    string tr = "f";
    tr.push_back(c);
    moves.push_back(tr);    
  }
  
  for (char c = '7'; c >= '2'; c--) {
    string tr = "e";
    tr.push_back(c);
    moves.push_back(tr);    
  }

  for (char c = '2'; c <= '7'; c++) {
    string tr = "d";
    tr.push_back(c);
    moves.push_back(tr);    
  }
  
  for (char c = '7'; c >= '2'; c--) {
    string tr = "c";
    tr.push_back(c);
    moves.push_back(tr);    
  }

  for (char c = '2'; c <= '7'; c++) {
    string tr = "b";
    tr.push_back(c);
    moves.push_back(tr);    
  }
  
  for (char c = '7'; c >= '2'; c--) {
    string tr = "a";
    tr.push_back(c);
    moves.push_back(tr);    
  }

  for (char c = 'a'; c <= 'h'; c++) {
    string tr = "";
    tr.push_back(c);
    tr += "8";
    moves.push_back(tr);
  }

  int n;
  cin >> n;

  cout << "a1 ";
  if (n == 15) {
    REP(i, 12) cout << moves[i] << " ";
    cout << "g6 g8 h8\n";
    return 0;
  }

  REP(i, n - 2) cout << moves[i] << " ";
  if (9 <= n && n <= 14) {
    cout << moves[n - 2];
    cout << " h8\n";
    return 0;
  }
  if (57 <= n && n <= 64) {
    cout << moves[n - 2];
    if (n != 64) cout << " h8\n";
    return 0;
  }

  char c = 'a';
  if (n > 2) c = moves[n - 3][0];
  string tr = "";
  tr.push_back(c);
  tr += "8";
  cout << tr << " h8\n"; 

  return 0;
}