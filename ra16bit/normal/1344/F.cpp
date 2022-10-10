#include <bits/stdc++.h>
using namespace std;
const int NB=30;
const string str="BRY";
int n,N,m,q,i,j,k,e,pos,cnt,w[1010][3],a[4040][1010],b[4040],c[4040],r[3030];
char op[7];
void setone(int i, int j) {
  a[i][j/NB]|=(1<<(j%NB));
}
int main() {
  scanf("%d%d",&n,&q);
  N=(n*3-1)/NB;
  for (i=0; i<n; i++, m++) {
    for (j=0; j<3; j++) {
      setone(m,i*3+j);
      w[i][j]=j;
    }
    b[m]=1;
  }
  while (q--) {
    scanf("%s",op);
    scanf("%d",&k);
    for (i=0; i<k; i++) {
      scanf("%d",&pos); --pos;
      if (op[0]=='m') {
        for (j=0; j<3; j++) setone(m+j,pos*3+w[pos][j]);
      } else if (op[0]=='Y') {
        swap(w[pos][0],w[pos][2]);
      } else if (op[1]=='Y') {
        swap(w[pos][1],w[pos][2]);
      } else {
        swap(w[pos][0],w[pos][1]);
      }
    }
    if (op[0]=='m') {
      if (k%2==0) for (j=0; j<3; j++) b[m+j]=1;
      scanf("%s",op);
      if (op[0]=='B') {
        b[m]^=1;
      } else if (op[0]=='R') {
        b[m+1]^=1;
      } else if (op[0]=='Y') {
        b[m+2]^=1;
      } else for (j=0; j<3; j++) b[m+j]^=1;
      m+=3;
    }
  }
  for (i=0; i<m; i++) {
    for (j=0; j<=N; j++) if (a[i][j]) break;
    c[i]=j*NB;
    if (j>N) {
      if (b[i]==1) { puts("NO"); return 0; }
      continue;
    }
    for (pos=0; pos<NB; pos++) if ((a[i][j]>>pos)&1) break;
    c[i]+=pos;
    for (k=i+1; k<m; k++) if ((a[k][j]>>pos)&1) {
      for (e=j; e<=N; e++) a[k][e]^=a[i][e];
      b[k]^=b[i];
    }
  }
  for (i=m-1; i>=0; i--) if (c[i]<n*3) {
    for (j=n*3-1; j>c[i]; j--) if (r[j]) b[i]^=((a[i][j/NB]>>(j%NB))&1);
    r[c[i]]=b[i];
  }
  puts("YES");
  for (i=0; i<n; i++) {
    for (cnt=j=0; j<3; j++) if (r[i*3+j]==1) { ++cnt; pos=j; }
    if (cnt==3) putchar('.'); else putchar(str[pos]);
  }
  return 0;
}