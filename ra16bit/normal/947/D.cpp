#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,m,q,i,sa[MX],ta[MX],sb,tb,sc[MX],tc[MX],se,te,sl,tl,sr,tr;
char s[MX],t[MX];
int main() {
  scanf("%s",s); n=strlen(s);
  scanf("%s",t); m=strlen(t);
  for (i=0; i<n; i++) if (s[i]=='A') {
    sa[i+1]=sa[i]+1;
    sc[i+1]=sc[i];
  } else {
    sa[i+1]=0;
    sc[i+1]=sc[i]+1;
  }
  for (i=0; i<m; i++) if (t[i]=='A') {
    ta[i+1]=ta[i]+1;
    tc[i+1]=tc[i];
  } else {
    ta[i+1]=0;
    tc[i+1]=tc[i]+1;
  }
  scanf("%d",&q);
  while (q--) {
    scanf("%d%d%d%d",&sl,&sr,&tl,&tr);
    sb=sc[sr]-sc[sl-1];
    tb=tc[tr]-tc[tl-1];
    se=min(sr-sl+1,sa[sr]);
    te=min(tr-tl+1,ta[tr]);
    if (sb==tb) printf("%d",int(se>=te && se%3==te%3));
      else if (sb==0) printf("%d",int(tb%2==0 && se>te));
        else printf("%d",int(sb<tb && sb%2==tb%2 && se>=te));
  }
  return 0;
}