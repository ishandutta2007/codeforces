#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,k,p;
  scanf("%i %i %i",&n,&k,&p);
  int l[n];
  for(int i = 0;i<n;i++)
    scanf("%i",&l[i]);
  int r[k];
  for(int i = 0;i<k;i++)
    scanf("%i",&r[i]);
  sort(l,l+n);
  sort(r,r+k);
  int ans = 2e9;
  int cur = 0;
  for(int i = 0;i<=k-n;i++){
    cur = 0;
    for(int j = i;j<i+n;j++)cur = max(cur,(abs(l[j-i]-r[j])+abs(r[j]-p)));
    ans = min(ans,cur);
  }
  printf("%i\n",ans);
  return 0;
}