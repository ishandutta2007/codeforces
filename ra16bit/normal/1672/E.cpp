#include <bits/stdc++.h>
using namespace std;
int n,le,ri,mid,x,cur,res,i;
int get_resp() {
  fflush(stdout);
  int resp;
  scanf("%d",&resp);
  return resp;
}
int ask(int x) {
  printf("? %d\n",x);
  return get_resp();
}
int main() {
  scanf("%d",&n);
  le=n+n-1; ri=n*2001;
  while (le<ri) {
    mid=(le+ri)/2;
    x=ask(mid);
    if (x==1) ri=mid; else le=mid+1;
  }
  res=ri;
  for (i=2; i<=n; i++) {
    cur=(ri+i-1)/i;
    while (cur*i>res) --cur;
    if (cur*i<ri+1-i) continue;
    x=ask(cur);
    if (x==0) break;
    res=min(res,x*cur);
  }
  printf("! %d\n",res);
  fflush(stdout);
  return 0;
}