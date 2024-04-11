#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,t,tp,x,y,r,a[4][57][100100],b[11][11],o[277];
char s[100100],c[22];
void add(int x, int y, int i, int v) {
  for (; i<=n; i=(i<<1)-(i&(i-1))) a[x][y][i]+=v;
}
int sum(int x, int y, int l, int r) {
  int res=0;
  for (; r>0; r&=r-1) res+=a[x][y][r];
  for (; l>0; l&=l-1) res-=a[x][y][l];
  return res;
}
int main() {
  o['A']=0;
  o['C']=1;
  o['G']=2;
  o['T']=3;
  for (i=1; i<=10; i++) for (j=0; j<i; j++, k++) b[i][j]=k;
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) for (j=1; j<=10; j++) add(o[s[i]],b[j][(i+1)%j],i+1,1);
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&tp,&x);
    if (tp==1) {
      scanf("%s",c);
      for (j=1; j<=10; j++) add(o[s[x-1]],b[j][x%j],x,-1);
      s[x-1]=c[0];
      for (j=1; j<=10; j++) add(o[s[x-1]],b[j][x%j],x,1);
    } else {
      scanf("%d",&y);
      scanf("%s",c);
      m=strlen(c);
      j=x%m;
      for (r=i=0; i<m; i++, j++) {
        if (j>=m) j=0;
        r+=sum(o[c[i]],b[m][j],x-1,y);
      }
      printf("%d\n",r);
    }
  }
  return 0;
}