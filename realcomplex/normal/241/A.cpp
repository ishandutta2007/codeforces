#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  scanf("%i %i",&n,&m);
  int a[n],b[n];
  for(int j = 0;j<n;j++)
    scanf("%i",&a[j]);
  for(int i = 0;i<n;i++)
    scanf("%i",&b[i]); 
  int mxs = 0;
  int cur = 0;
  int ans = 0;
  for(int i = 0;i<n;i++){
    mxs = max(mxs,b[i]);
    cur += b[i];
    while(cur<a[i])
      cur+=mxs,ans+=m;
    cur -= a[i];
    ans += a[i];
  }
  printf("%i\n",ans);
  return 0;
}