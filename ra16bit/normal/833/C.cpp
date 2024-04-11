#include <bits/stdc++.h>
using namespace std;
int n,m,i,a[22],b[22],c[22],cc[22],d[22],e[22];
long long l,ll,r,rr,res,pw10[22];
void rec(int lev, int cnt) {
  if (lev==10) {
    if (cnt==0) return;
    for (int i=0; i<10; i++) cc[i]=c[i];
//    for (int i=0; i<10; i++) for (int j=0; j<cc[i]; j++) printf("%d",i); puts("");
    if (n==m) {
      int i=n-1;
      cc[0]=n-cnt;
      for (; i>=0; i--) if (a[i]==b[i]) {
        if (cc[a[i]]==0) return;
        cc[a[i]]--;
      } else break;
      if (i<0) { res++; return; }
      for (int ii=a[i]+1; ii<b[i]; ii++) if (cc[ii]>0) { res++; return; }
      if (cc[a[i]]>0) {
        cc[a[i]]--;
//        printf("ai=%d\n",a[i]);
//        for (int i=0; i<10; i++) for (int j=0; j<cc[i]; j++) printf("%d",i); puts("low");
        int e=i-1,ii=9;
        for (; ii>=0; ii--) {
          int j=0;
          for (; j<cc[ii]; j++) {
            if (ii!=a[e]) {
              if (ii>a[e]) {
//              printf("++ %d @ %d\n",ii,a[e]);
              res++; return; }
              break;
            }
            e--;
          }
          if (j<cc[ii]) break;
        }
        if (ii<0) {
//        puts("++ low");
        res++; return; }
        cc[a[i]]++;
      }
      if (cc[b[i]]>0) {
        cc[b[i]]--;
        /*printf("bi=%d\n",b[i]);
        for (int i=0; i<10; i++) for (int j=0; j<cc[i]; j++) printf("%d",i); puts("high");*/
        int e=i-1,ii=0;
        for (; ii<10; ii++) {
          int j=0;
          for (; j<cc[ii]; j++) {
            if (ii!=b[e]) {
              if (ii<b[e]) {
//              printf("++ %d # %d\n",ii,b[e]);
              res++; return; }
              break;
            }
            e--;
          }
          if (j<cc[ii]) break;
        }
        if (ii>9) { 
//        puts("++ high");
        res++; return; }
        cc[b[i]]++;
      }
    } else {
      long long cur=0;
      int z=m-cnt;
      for (int i=0; i<10; i++) d[i]=cc[i];
      int i=1;
      for (; i<10; i++) if (cc[i]!=0) { cur=i; cc[i]--; break; }
      cur*=pw10[z];
      for (; i<10; i++) while (cc[i]!=0) { cur=cur*10+i; cc[i]--; }
      if (cur>=l && cur<=r) { res++; return; }
      for (i=9; i>0; i--) if (d[i]!=0) { cur=i; d[i]--; break; }
      if (z>0) cur*=pw10[z-1];
      for (; i>0; i--) while (d[i]!=0) { cur=cur*10+i; d[i]--; }
      if (cur>=l && cur<=r) res++;
    }
    return;
  }
  for (int i=0; cnt+i<=m; i++) {
    c[lev]=i;
    rec(lev+1,cnt+i);
  }
}
int main() {
  for (pw10[0]=i=1; i<22; i++) pw10[i]=pw10[i-1]*10LL;
  cin>>l>>r;
  for (ll=l; ll>0; ll/=10) a[n++]=ll%10;
  for (rr=r; rr>0; rr/=10) b[m++]=rr%10;
  rec(1,0);
  cout<<res<<'\n';
  return 0;
}