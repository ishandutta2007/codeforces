#include <bits/stdc++.h>
using namespace std;
int n,i,j,k,cj,cw,cur,wlen,st[3030],len[3030],le[3030],ri[3030],p[9009000];
char a[9009000],b[9009000],zle,zri;
bool wle,wri;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    st[i]=cur;
    scanf("%s",a+cur);
    cur+=strlen(a+cur);
  }
  st[n]=cur; cw=-1;
  for (cur=i=0; i<n; i++) {
    scanf("%s",b+cur);
    len[i]=strlen(b+cur);
    le[i]=-1;
    for (j=0; j<len[i]; j++) if (a[cur+j]!=b[cur+j]) {
      if (le[i]==-1) le[i]=j;
      ri[i]=j;
    }
    if (le[i]>=0) {
      if (cw>=0) {
        if (ri[i]-le[i]!=ri[cw]-le[cw]) { puts("NO"); return 0; }
        for (j=le[i], cj=le[cw]; j<=ri[i]; j++, cj++) if (a[st[cw]+cj]!=a[cur+j] || b[st[cw]+cj]!=b[cur+j]) break;
        if (j<=ri[i]) { puts("NO"); return 0; }
      } else cw=i;
    }
    cur+=len[i];
    assert(cur==st[i+1]);
  }
  assert(cw!=-1);
  if (cw==-1) {
    puts("YES\na\na");
    return 0;
  }
  wle=wri=true;
  while (wle || wri) {
    zle=zri=0;
    for (i=0; i<n; i++) if (le[i]!=-1) {
      if (wle) {
        if (le[i]==0) wle=false;
        if (zle==0) zle=a[st[i]+le[i]-1]; else if (zle!=a[st[i]+le[i]-1]) wle=false;
      }
      if (wri) {
        if (ri[i]+1==len[i]) wri=false;
        if (zri==0) zri=a[st[i]+ri[i]+1]; else if (zri!=a[st[i]+ri[i]+1]) wri=false;
      }
    }
    if (zle==0) wle=false;
    if (zri==0) wri=false;
    if (wle) for (i=0; i<n; i++) if (le[i]!=-1) le[i]--;
    if (wri) for (i=0; i<n; i++) if (le[i]!=-1) ri[i]++;
  }
  wlen=ri[cw]-le[cw]+1;
  for (i=st[n]; i>=0; i--) a[i+wlen+1]=a[i];
  a[wlen]='$';
  for (i=0; i<wlen; i++) a[i]=a[st[cw]+le[cw]+i+wlen+1];
  for (i=1, j=0; i<st[n]+wlen+1; i++) {
    while (j>0 && a[j]!=a[i]) j=p[j-1];
    if (a[j]==a[i]) j++;
    p[i]=j;
  }
  for (i=0; i<n; i++) {
    for (j=wlen-1; j<len[i]; j++) if (p[st[i]+j+wlen+1]==wlen) {
      for (k=0; k<wlen; k++) a[st[i]+j+wlen+1-k]=b[st[cw]+ri[cw]-k];
      break;
    }
  }
  for (i=0; i<st[n]; i++) if (a[wlen+1+i]!=b[i]) { puts("NO"); return 0; }
  puts("YES");
  for (i=0; i<wlen; i++) putchar(a[i]);
  putchar('\n');
  for (i=0; i<wlen; i++) putchar(b[st[cw]+le[cw]+i]);
  putchar('\n');
  return 0;
}