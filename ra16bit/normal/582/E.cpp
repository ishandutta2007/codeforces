#include <stdio.h>
const int md=1000000007;
int num,n,cur,r,f[222][65777],a[22],b[22],c[65777];
long long sl[65777],sr[65777];
char s[555];
void dfs(int i) {
  int l=0,r=0;
  if (s[cur]=='(') {
    cur++;
    l=++num;
    dfs(num);
    cur++;
  }
  char a=s[cur++];
  if (s[cur]=='(') {
    cur++;
    r=++num;
    dfs(num);
    cur++;
  }
  if (l) {
    if (a=='|' || a=='?') {
      for (int mask=0; mask<(1<<16); mask++) {
        sl[mask]=f[l][mask];
        sr[mask]=f[r][mask];
      }
      for (int k=0; k<16; k++) for (int mask=0; mask<(1<<16); mask++) if ((mask>>k)&1) {
        sl[mask]=(sl[mask]+sl[mask^(1<<k)])%md;
        sr[mask]=(sr[mask]+sr[mask^(1<<k)])%md;
      }
      for (int mask=0; mask<(1<<16); mask++) c[mask]=(sl[mask]*sr[mask])%md;
      for (int k=0; k<16; k++) for (int mask=0; mask<(1<<16); mask++) if ((mask>>k)&1) c[mask]=(c[mask]+md-c[mask^(1<<k)])%md;
      for (int mask=0; mask<(1<<16); mask++) f[i][mask]=(f[i][mask]+c[mask])%md;
    }
    if (a=='&' || a=='?') {
      for (int mask=(1<<16)-1; mask>=0; mask--) {
        sl[mask]=f[l][mask];
        sr[mask]=f[r][mask];
      }
      for (int k=0; k<16; k++) for (int mask=(1<<16)-1; mask>=0; mask--) if (((mask>>k)&1)==0) {
        sl[mask]=(sl[mask]+sl[mask^(1<<k)])%md;
        sr[mask]=(sr[mask]+sr[mask^(1<<k)])%md;
      }
      for (int mask=(1<<16)-1; mask>=0; mask--) c[mask]=(sl[mask]*sr[mask])%md;
      for (int k=0; k<16; k++) for (int mask=(1<<16)-1; mask>=0; mask--) if (((mask>>k)&1)==0) c[mask]=(c[mask]+md-c[mask^(1<<k)])%md;
      for (int mask=(1<<16)-1; mask>=0; mask--) f[i][mask]=(f[i][mask]+c[mask])%md;
    }
  } else for (int j=0; j<4; j++) {
    if (a=='?' || a-j=='A') {
      int mask=0;
      for (int k=0; k<16; k++) if ((k>>j)&1) mask+=1<<k;
       f[i][mask]++;
    }
    if (a=='?' || a-j=='a') {
      int mask=0;
      for (int k=0; k<16; k++) if (((k>>j)&1)==0) mask+=1<<k;
      f[i][mask]++;
    }
  }
  //printf("%d: %d %d\n",i,l,r);
  //for (int mask=0; mask<(1<<16); mask++) if (f[i][mask]) printf("%d %d = %d\n",i,mask,f[i][mask]);
}
int main() {
  scanf("%s",&s);
  dfs(0);
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    int mask=0,x;
    for (int j=0; j<4; j++) {
      scanf("%d",&x);
      a[i]+=x*(1<<j);
    }
    scanf("%d",&b[i]);
  }
  for (int mask=0; mask<(1<<16); mask++) {
    int i=0;
    for (; i<n; i++) if (((mask>>a[i])&1)!=b[i]) break;
    if (i>=n) r=(r+f[0][mask])%md;
  }
  printf("%d\n",r);
  return 0;
}