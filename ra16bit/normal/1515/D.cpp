#include <bits/stdc++.h>
using namespace std;
int t,n,l,r,cl,cr,totl,totr,res,x,i,j,p;
pair<int,int> c[200200];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d",&n,&l,&r);
    for (i=0; i<n; i++) {
      scanf("%d",&c[i].first);
      c[i].second=i;
    }
    sort(c,c+n);
    p=r-l;
    for (totl=totr=res=i=0; i<n; i=j) {
      cl=cr=0;
      for (j=i; j<n && c[i].first==c[j].first; j++) if (c[j].second<l) ++cl; else ++cr;
      if (cl>cr) {
        cl-=cr;
        if (p<0) {
          x=min(cl,-p);
          if (x&1) x--;
          p+=x;
          res+=x/2;
          totl+=cl-x;
        } else totl+=cl;
      } else {
        cr-=cl;
        if (p>0) {
          x=min(cr,p);
          if (x&1) x--;
          p-=x;
          res+=x/2;
          totr+=cr-x;
        } else totr+=cr;
      }
    }
    res+=totl+totr-min(totl,totr);
    printf("%d\n",res);
  }
  return 0;
}