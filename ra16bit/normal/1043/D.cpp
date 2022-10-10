#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,prv,a[12][100100],b[100100];
set<int> s;
long long r;
long long sum(long long x) {
  return (x*(x+1LL))/2;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) for (j=0; j<n; j++) {
    scanf("%d",&a[i][j]);
    if (i==0) b[a[i][j]]=j;
    a[i][j]=b[a[i][j]];
  }
  s.insert(0);
  s.insert(n);
  for (i=1; i<m; i++) for (j=0; j<n; j=k) {
    for (k=j+1; k<n && a[i][k]==a[i][k-1]+1; k++);
    s.insert(a[i][j]);
    s.insert(a[i][j]+k-j);
  }
  for (auto it=s.begin(); it!=s.end(); it++) {
    if (it!=s.begin()) r+=sum(*it-prv);
    prv=*it;
  }
  printf("%I64d\n",r);
  return 0;
}