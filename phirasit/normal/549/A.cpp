#include <stdio.h>
#include <set>

using namespace std;
const int N = 110;

set<char> S;

char str[N][N];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0;i < n;i++) {
    scanf("%s", str[i]);
  }
  int ans = 0;
  S.insert('f');
  S.insert('a');
  S.insert('c');
  S.insert('e');
  for(int i = 0;i < n-1;i++) {
    for(int j = 0;j < m-1;j++) {
      set<char> a;
      a.insert(str[i][j]);
      a.insert(str[i+1][j]);
      a.insert(str[i][j+1]);
      a.insert(str[i+1][j+1]);
      if(S == a) {
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}