#include <bits/stdc++.h>
using namespace std;
int i,j,cnt;
char s[11];
int main() {
  for (i=2; i<=50; i++) {
    for (j=2; j<i; j++) if (i%j==0) break;
    if (i==j) {
      if (i*i<=100) {
        printf("%d\n",i*i);
        fflush(stdout);
        scanf("%s",s);
        if (s[0]=='y') {
          puts("composite");
          fflush(stdout);
          return 0;
        }
      }
      printf("%d\n",i);
      fflush(stdout);
      scanf("%s",s);
      if (s[0]=='y') cnt++;
    }
  }
  puts((cnt<2)?"prime":"composite");
  fflush(stdout);
  return 0;
}