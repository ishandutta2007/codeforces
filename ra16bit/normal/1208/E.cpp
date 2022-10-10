#include <bits/stdc++.h>
using namespace std;
const int MX=1010100;
int n,w,i,j,stw,cur,best[MX],a[MX],b[MX],c[MX],st[MX],len[MX];
long long ans[MX],res;
multiset<int> s;
int main() {
  scanf("%d%d",&n,&w);
  for (i=0; i<n; i++) {
    scanf("%d",&len[i]);
    st[i+1]=st[i]+len[i];
    for (j=st[i]; j<st[i+1]; j++) {
      scanf("%d",&a[j]);
      if (j==st[i]) b[j]=a[j]; else b[j]=max(b[j-1],a[j]);
    }
    c[st[i+1]-1]=a[st[i+1]-1];
    for (j=st[i+1]-2; j>=st[i]; j--) c[j]=max(c[j+1],a[j]);
    best[i]=max(0,c[st[i]]);
    res+=best[i];
  }
  for (i=0; i<n; i++) {
    if (len[i]*2>w) {
      for (j=0; j<w; j++) {
        stw=w-len[i];
        if (j<len[i]) s.insert(-a[st[i]+j]);
        cur=*s.begin();
        if (cur>0 && (j>=len[i] || j<stw)) cur=0;
        ans[j]+=best[i]+cur;
        if (j>=stw) s.erase(s.find(-a[st[i]+j-stw]));
      }
    } else {
      for (j=0; j<len[i]; j++) ans[j]+=best[i]-max(0,b[st[i]+j]);
      for (j=1; j<=len[i]; j++) ans[w-j]+=best[i]-max(0,c[st[i+1]-j]);
    }
  }
  for (i=0; i<w; i++) printf("%I64d ",res-ans[i]);
  return 0;
}