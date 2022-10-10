#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,n,m,r,i,j,mx,p[MX],rk[MX],tot[MX],cnt[MX][28];
char s[MX];
int fs(int x) {
  if (x!=p[x]) p[x]=fs(p[x]);
  return p[x];
}
void un(int a, int b) {
  if (a==b) return;
  if (rk[a]>=rk[b]) {
    p[b]=a;
    tot[a]+=tot[b];
    if (rk[a]==rk[b]) ++rk[a];
  } else {
    p[a]=b;
    tot[b]+=tot[a];
  }
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    for (i=0; i<n; i++) {
      p[i]=i;
      rk[i]=1;
      tot[i]=1;
      if (i>=m) un(fs(i),fs(i-m));
      if (i>n-i-1) un(fs(i),fs(n-i-1));
    }
    for (i=0; i<n; i++) if (fs(i)==i) for (j=0; j<26; j++) cnt[i][j]=0;
    for (i=0; i<n; i++) ++cnt[fs(i)][s[i]-'a'];
    for (r=i=0; i<n; i++) if (fs(i)==i) {
      for (mx=j=0; j<26; j++) if (cnt[i][j]>cnt[i][mx]) mx=j;
      r+=tot[i]-cnt[i][mx];
    }
    printf("%d\n",r);
  }
  return 0;
}