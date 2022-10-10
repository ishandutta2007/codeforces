#include <bits/stdc++.h>
using namespace std;
const int MX=500500;
int n,m,i,j,k,top,st[MX],a[MX];
char s[MX];
long long lft[MX],len[MX],pos,res;
long long inside(long long len) {
  return (len*(len+1LL)*(len+2LL))/6LL;
}
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  for (i=0; i<n; i=j) if (s[i]=='1') {
    for (j=i; j<n && s[j]=='1'; j++);
    len[++m]=j-i;
    st[m]=i;
    res+=inside(len[m]);
    for (k=1; k<=len[m]; k++) {
      while (top>0 && len[a[top]]<=k) --top;
      pos=top?st[a[top]]+len[a[top]]-k:0;
      res+=(st[m]-pos)*k;
    }
    lft[m]=pos;
    a[++top]=m;
  } else j=i+1;
  top=0;
  for (i=m; i>0; i--) {
    for (k=1; k<=len[i]; k++) {
      while (top>0 && len[a[top]]<k) --top;
      pos=top?st[a[top]]+k-1:n;
      res+=(pos-(st[i]+len[i]))*k;
    }
    res+=(st[i]-lft[i])*(pos-(st[i]+len[i]))*len[i];
    a[++top]=i;
  }
  printf("%I64d\n",res);
  return 0;
}