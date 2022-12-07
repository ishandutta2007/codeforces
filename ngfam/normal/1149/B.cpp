#include <bits/stdc++.h>

using namespace std;

const int M = 256;
const int N = 100020;

int n, q;
char s[N];
int sz[5];
int f[M][M][M];
int jump[N][26];

char str[4][M];

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> n >> q >> (s + 1);

  memset(jump, 60, sizeof jump);

  for(int i = n; i >= 1; --i) {
    for(int j = 0; j < 26; ++j) {
      jump[i][j] = jump[i + 1][j];
    }
    jump[i][s[i] - 'a'] = i;
  }


  memset(f, 60, sizeof f);

  f[0][0][0] = 0;

  for(int t = 1; t <= q; ++t) {
    char c; cin >> c;
    if(c == '+') {
     // cout << "YES?" << endl;
      int x; cin >> x >> c;

      str[x][++sz[x]] = c;
      if(x == 1) {

        for(int j = 0; j <= sz[2]; ++j) {
          for(int k = 0; k <= sz[3]; ++k) {
            f[sz[x]][j][k] = n + 1;
            if(sz[x] > 0 && f[sz[x] - 1][j][k] < n) f[sz[x]][j][k] = min(f[sz[x]][j][k], jump[f[sz[x] - 1][j][k] + 1][c - 'a']);
            if(j > 0 && f[sz[x]][j - 1][k] < n) f[sz[x]][j][k] = min(f[sz[x]][j][k], jump[f[sz[x]][j - 1][k] + 1][str[2][j] - 'a']);
            if(k > 0 && f[sz[x]][j][k - 1] < n) f[sz[x]][j][k] = min(f[sz[x]][j][k], jump[f[sz[x]][j][k - 1] + 1][str[3][k] - 'a']);

         //   cout << j << " " << k << endl;
          }
        } 
      }
      else if(x == 2) {
        for(int j = 0; j <= sz[1]; ++j) {
          for(int k = 0; k <= sz[3]; ++k) {
            f[j][sz[x]][k] = n + 1;
            if(sz[x] > 0 && f[j][sz[x] - 1][k] < n) f[j][sz[x]][k] = min(f[j][sz[x]][k], jump[f[j][sz[x] - 1][k] + 1][c - 'a']);
            if(j > 0 && f[j - 1][sz[x]][k] < n) f[j][sz[x]][k] = min(f[j][sz[x]][k], jump[f[j - 1][sz[x]][k] + 1][str[1][j] - 'a']);
            if(k > 0 && f[j][sz[x]][k - 1] < n) f[j][sz[x]][k] = min(f[j][sz[x]][k], jump[f[j][sz[x]][k - 1] + 1][str[3][k] - 'a']); 
          }
        }
      }
      else {
        for(int j = 0; j <= sz[1]; ++j) {
          for(int k = 0; k <= sz[2]; ++k) {
            f[j][k][sz[x]] = n + 1;
            if(sz[x] > 0 && f[j][k][sz[x] - 1] < n) f[j][k][sz[x]] = min(f[j][k][sz[x]], jump[f[j][k][sz[x] - 1] + 1][c - 'a']);
            if(j > 0 && f[j - 1][k][sz[x]] < n) f[j][k][sz[x]] = min(f[j][k][sz[x]], jump[f[j - 1][k][sz[x]] + 1][str[1][j] - 'a']);
            if(k > 0 && f[j][k - 1][sz[x]] < n) f[j][k][sz[x]] = min(f[j][k][sz[x]], jump[f[j][k - 1][sz[x]] + 1][str[2][k] - 'a']);
          }
        }
      }
    }
    else {
      int x; cin >> x;
      --sz[x];
    }

    if(f[sz[1]][sz[2]][sz[3]] <= n) cout << "YES" << endl; 
    else cout << "NO" << endl;

   // / cout << f[sz[1]][sz[2]][sz[3]] << endl;
  }

  return 0;
}