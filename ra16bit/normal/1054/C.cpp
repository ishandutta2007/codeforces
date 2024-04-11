#include <bits/stdc++.h>
using namespace std;
int n,a[1010],l[1010],r[1010],i,k,cnt,o;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&l[i]);
  for (i=0; i<n; i++) scanf("%d",&r[i]);
  for (k=n; k>0; k-=cnt) {
    for (cnt=i=0; i<n; i++) if (a[i]==0 && l[i]==0 && r[i]==0) {
      a[i]=k;
      cnt++;
    }
    o=cnt;
    for (i=0; i<n; i++) if (a[i]==0) r[i]-=o; else if (a[i]==k) o--;
    o=cnt;
    for (i=n-1; i>=0; i--) if (a[i]==0) l[i]-=o; else if (a[i]==k) o--;
    if (cnt==0) break;
  }
  if (k==0) {
    puts("YES");
    for (i=0; i<n; i++) printf("%d ",a[i]);
  } else puts("NO");
  return 0;
}