#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=(1<<19);
int i,j,k,n,N,num,a[19][MX];
pii b[MX];
char s[MX];
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  num=N=(1<<n);
  for (i=0; i<N; i++) a[0][i]=s[i]-'a';
  for (num=i=1; i<=n; i++) {
    for (k=0; k<N; k+=num*2) {
      for (j=0; j<num; j++) b[k+j]=make_pair(a[i-1][k+j],a[i-1][k+j+num]);
      for (; j<2*num; j++) b[k+j]=make_pair(a[i-1][k+j],a[i-1][k+j-num]);
    }
    //for (j=0; j<N; j++) printf("[%d,%d] ",b[j].first,b[j].second); printf(" =b\n");
    sort(b,b+N);
    //for (j=0; j<N; j++) printf("[%d,%d] ",b[j].first,b[j].second); printf(" =b(s)\n");
    for (k=0; k<N; k+=num*2) {
      for (j=0; j<num; j++) a[i][k+j]=lower_bound(b,b+N,make_pair(a[i-1][k+j],a[i-1][k+j+num]))-b;
      for (; j<2*num; j++) a[i][k+j]=lower_bound(b,b+N,make_pair(a[i-1][k+j],a[i-1][k+j-num]))-b;
    }
    //for (j=0; j<N; j++) printf("%d ",a[i][j]); printf(" =%d\n",i);
    num*=2;
  }
  for (k=i=0; i<N; i++) if (a[n][i]<a[n][k]) k=i;
  for (i=0; i<N; i++) putchar(s[i^k]);
  return 0;
}