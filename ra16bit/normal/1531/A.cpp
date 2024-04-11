#include <bits/stdc++.h>
using namespace std;
int n,i;
string s,cur;
char st[22];
bool ok=true;
int main() {
  cur="blue";
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",st);
    s=st;
    if (s=="lock") {
      ok=false;
    } else if (s=="unlock") {
      ok=true;
    } else if (ok) {
      cur=s;
    }
  }
  puts(cur.c_str());
  return 0;
}