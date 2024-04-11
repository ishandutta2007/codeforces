#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,i;
char s[2][200200];
void norm(int l, int r) {
  if ((r-l)%2) return;
  int h=(l+r)/2;
  norm(l,h);
  norm(h,r);
  for (int j=0; j<2; j++) {
    int i=l;
    for (i=l; i<h; i++) if (s[j][i]!=s[j][h+i-l]) break;
    if (i<h && s[j][i]>s[j][h+i-l]) for (i=l; i<h; i++) swap(s[j][i],s[j][h+i-l]);
  }
}
int main() {
  scanf("%s",s[0]);
  scanf("%s",s[1]);
  n=strlen(s[0]);
  norm(0,n);
  norm(0,n);
  for (i=0; i<n; i++) if (s[0][i]!=s[1][i]) { puts("NO"); return 0; }
  puts("YES");
  return 0;
}