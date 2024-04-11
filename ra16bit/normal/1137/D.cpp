#include <bits/stdc++.h>
using namespace std;
int n,i;
char s[14][14];
int main() {
  while (true) {
    puts("next 0 1");
    fflush(stdout);
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%s",s[i]);
    puts("next 0");
    fflush(stdout);
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%s",s[i]);
    if (n==2) break;
  }
  while (true) {
    puts("next 0 1 2 3 4 5 6 7 8 9");
    fflush(stdout);
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%s",s[i]);
    if (n==1) break;
  }
  puts("done");
  return 0;
}