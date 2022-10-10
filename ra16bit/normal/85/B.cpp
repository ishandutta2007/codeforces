#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int n,i,j,st,t[3],fi[3],fr[3];
long long cur,res,q[3][MX];
int main() {
  for (j=0; j<3; j++) {
    scanf("%d",&st);
    for (i=0; i<min(st,100000); i++) q[j][fr[j]++]=1;
  }
  for (j=0; j<3; j++) scanf("%d",&t[j]);
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&st);
    cur=st;
    for (j=0; j<3; j++) {
      cur=max(cur,q[j][fi[j]++]);
      cur+=t[j];
      q[j][fr[j]++]=cur;
    }
    res=max(res,cur-st);
  }
  cout<<res;
  return 0;
}