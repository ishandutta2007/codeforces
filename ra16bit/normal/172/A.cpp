#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int n,i;
string s[31234];
char st[22];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",st);
    s[i]=st;
  }
  sort(s,s+n);
  for (i=0; ; i++) if (s[0][i]!=s[n-1][i]) break;
  printf("%d\n",i);
  return 0;
}