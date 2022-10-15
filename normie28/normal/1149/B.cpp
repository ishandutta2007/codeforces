#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1e5 + 18;
const int maxl = 251;
const int alpha = 30;
string st;
int n, Q;
int nxt[maxn][alpha];
int len[5];
int F[maxl][maxl][maxl];
char s[5][maxl];
 
void Input() {
   cin >> n >> Q >> st;
   st = '*' + st;
   for (int i = 0; i <= n + 2; i++) {
      for (int ch = 0; ch <= 'z' - 'a'; ch++) {
         nxt[i][ch] = n + 1;
      }
   }
   for (int i = n + 1; i >= 0; i--) {
      for (int ch = 0; ch <= 'z' - 'a'; ch++) {
         nxt[i][ch] = nxt[i + 1][ch];
      }
      if (i < n) nxt[i][st[i + 1] - 'a'] = i + 1;
   }
}
 
void minimize(int &a, int b) {
   if (a > b) a = b;
}
 
void Update(int pos, char ch) {
   int x = ++len[pos];
   s[pos][len[pos]] = ch;
   for (int i = 0; i <= 250; i++) {
      for (int j = 0; j <= 250; j++) {
         if (pos == 1) {
            minimize(F[x][i][j], nxt[F[x - 1][i][j]][ch - 'a']);
            if (i > 0 && i <= len[2]) minimize(F[x][i][j], nxt[F[x][i - 1][j]][s[2][i] - 'a']);
            if (j > 0 && j <= len[3]) minimize(F[x][i][j], nxt[F[x][i][j - 1]][s[3][j] - 'a']);
         }
         if (pos == 2) {
            if (i > 0 && i <= len[1]) minimize(F[i][x][j], nxt[F[i - 1][x][j]][s[1][i] - 'a']);
            minimize(F[i][x][j], nxt[F[i][x - 1][j]][ch - 'a']);
            if (j > 0 && j <= len[3]) minimize(F[i][x][j], nxt[F[i][x][j - 1]][s[3][j] - 'a']);
         }
         if (pos == 3) {
            if (i > 0 && i <= len[1]) minimize(F[i][j][x], nxt[F[i - 1][j][x]][s[1][i] - 'a']);
            if (j > 0 && j <= len[2]) minimize(F[i][j][x], nxt[F[i][j - 1][x]][s[2][j] - 'a']);
            minimize(F[i][j][x], nxt[F[i][j][x - 1]][ch - 'a']);
         }
      }
   }
}
 
void Erase(int pos) {
   int x = len[pos];
   len[pos]--;
   for (int i = 0; i <= 250; i++) {
      for (int j = 0; j <= 250; j++) {
         if (pos == 1) F[x][i][j] = n + 1;
         if (pos == 2) F[i][x][j] = n + 1;
         if (pos == 3) F[i][j][x] = n + 1;
      }
   }
}
 
void Output() {
   for (int i = 0; i <= 250; i++) {
      for (int j = 0; j <= 250; j++) {
         for (int k = 0; k <= 250; k++) {
            F[i][j][k] = n + 1;
         }
      }
   }
   F[0][0][0] = 0;
   for (int i = 1; i <= Q; i++) {
      char Order;
      cin >> Order;
      if (Order == '+') {
         int pos;
         char ch;
         cin >> pos >> ch;
         Update(pos, ch);
      }
      else {
         int pos;
         cin >> pos;
         Erase(pos);
      }
      if (F[len[1]][len[2]][len[3]] == n + 1) cout << "NO\n";
      else cout << "YES\n";
   }
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
  Input(); Output();
}