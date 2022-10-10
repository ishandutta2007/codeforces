#include <bits/stdc++.h>
using namespace std;
const int MX=1000100;
int t,n,i,p,l,r,k,len,wl,res,a1[MX],a2[MX];
char s[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s);
    n=strlen(s);
    for (i=0; i<n-i-1; i++) if (s[i]!=s[n-i-1]) break;
    if (i>=n-i-1) {
      puts(s);
      continue;
    } else p=i;
    res=p*2; wl=p;
    for (i=l=0, r=-1; i<n; i++) {
      if (i>r) k=1; else k=min(a1[l+r-i],r-i);
      for (; i+k<n && i-k>=0 && s[i+k]==s[i-k]; k++);
      a1[i]=k--;
      if (i+k>r) { l=i-k; r=i+k; }
      //printf("%d",a1[i]);
      len=min(i-a1[i]+1,n-(i+a1[i]));
      if (len<=p && 2*a1[i]-1+2*len>res) {
        res=2*a1[i]-1+2*len;
        if (len==i-a1[i]+1) wl=i+a1[i]; else wl=len;
      }
    }
    //puts("");
    for (i=l=0, r=-1; i<n; i++) {
      if (i>r) k=1; else k=min(a2[l+r-i+1],r-i+1)+1;
      for (; i+k-1<n && i-k>=0 && s[i+k-1]==s[i-k]; k++);
      a2[i]=--k;
      if (i+k-1>r) { l=i-k; r=i+k-1; }
      //printf("%d",a2[i]);
      if (a2[i]>0) {
        len=min(i-a2[i],n-(i+a2[i]));
        if (len<=p && 2*(a2[i]+len)>res) {
          res=2*(a2[i]+len);
          if (len==i-a2[i]) wl=i+a2[i]; else wl=len;
        }
      }
    }
    //puts("");
    //printf("%d\n",res);
    for (i=0; i<wl; i++) putchar(s[i]);
    for (i=n-(res-wl); i<n; i++) putchar(s[i]);
    putchar('\n');
  }
  return 0;
}