#include <bits/stdc++.h>
using namespace std;
int n,i,a[17];
bool q;
void rec(int l, int s) {
  if (l==n) {
    if (s%360==0) q=true;
    return;
  }
  rec(l+1,s+a[l]);
  rec(l+1,s-a[l]);
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  rec(0,0);
  puts(q?"YES":"NO");
  return 0;
}