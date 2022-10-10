#include <bits/stdc++.h>
using namespace std;
int n,i;
char st[111];
string s;
set<string> a;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",st);
    s=st;
    if (a.count(s)) puts("YES"); else {
      a.insert(s);
      puts("NO");
    }
  }
  return 0;
}