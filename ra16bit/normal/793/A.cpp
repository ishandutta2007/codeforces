#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,a[100100];
long long r;
bool q=true;
int main() {
  scanf("%d%d",&n,&m);
  for (i=j=0; i<n; i++) {
    scanf("%d",&a[i]);
    if (a[i]%m!=a[0]%m) q=false;
    if (a[i]<a[j]) j=i;
  }
  if (!q) { puts("-1"); return 0; }
  for (i=0; i<n; i++) r+=(a[i]-a[j])/m;
  cout << r << '\n';
  return 0;
}