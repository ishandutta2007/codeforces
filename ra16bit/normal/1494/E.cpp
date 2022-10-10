#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,x,y,q;
char s[5];
set<pii> b,p;
map<pii,char> e;
pii c,d,o;
int main() {
  scanf("%d%d",&n,&q);
  while (q--) {
    scanf("%s",s);
    if (s[0]=='?') {
      scanf("%d",&x);
      if (x&1) puts(p.empty()?"NO":"YES"); else puts(b.empty()?"NO":"YES"); 
    } else {
      scanf("%d%d",&x,&y);
      c={x,y};
      o={y,x};
      d={min(x,y),max(x,y)};
      if (s[0]=='+') {
        scanf("%s",s);
        auto it=e.find(o);
        if (it!=e.end()) {
          p.insert(d);
          if (s[0]==it->second) b.insert(d);
        }
        e[c]=s[0];
      } else {
        if (p.count(d)) p.erase(d);
        if (b.count(d)) b.erase(d);
        e.erase(c);
      }
    }
  }
  return 0;
}