#include <bits/stdc++.h>
using namespace std;
int n,i,j;
long long r;
pair<long long,int> a[7070];
bool u[7070];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%I64d",&a[i].first);
  for (i=0; i<n; i++) scanf("%d",&a[i].second);
  sort(a,a+n);
  for (i=1; i<n; i++) if (a[i].first==a[i-1].first) u[i]=u[i-1]=true;
  for (i=n-1; i>=0; i--) if (!u[i]) for (j=i+1; j<n; j++)
    if (u[j] && (a[j].first&a[i].first)==a[i].first && (a[j].first|a[i].first)==a[j].first) u[i]=true;
  for (i=0; i<n; i++) if (u[i]) r+=a[i].second;
  printf("%I64d\n",r);
  return 0;
}