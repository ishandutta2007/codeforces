#include <bits/stdc++.h>
using namespace std;
int n,i,q;
string s[100100];
char st[22];
bool ok=true;
set<int> l,c,uc;
int fndlst() {
  auto ut=uc.end();
  --ut;
  auto lt=l.lower_bound(*ut);
  auto ct=c.lower_bound(*lt);
  --ct;
  return *ct;
}
int main() {
  scanf("%d",&n);
  s[0]="blue";
  c.insert(0);
  uc.insert(0);
  s[n+1]="lock";
  l.insert(n+1);
  for (i=1; i<=n; i++) {
    scanf("%s",st);
    s[i]=st;
    if (s[i]=="lock") l.insert(i); else if (s[i]!="unlock") {
      c.insert(i);
      if (s[i-1]=="unlock") uc.insert(i);
    }
  }
  puts(s[fndlst()].c_str());
  scanf("%d",&q);
  while (q--) {
    scanf("%d",&i);
    scanf("%s",st);
    if (s[i]=="lock") l.erase(i); else if (s[i]=="unlock") {
      if (s[i+1]!="lock" && s[i+1]!="unlock") uc.erase(i+1);
    } else {
      c.erase(i);
      if (s[i-1]=="unlock") uc.erase(i);
    }
    s[i]=st;
    if (s[i]=="lock") l.insert(i); else if (s[i]=="unlock") {
      if (s[i+1]!="lock" && s[i+1]!="unlock") uc.insert(i+1);
    } else {
      c.insert(i);
      if (s[i-1]=="unlock") uc.insert(i);
    }
    puts(s[fndlst()].c_str());
  }
  return 0;
}