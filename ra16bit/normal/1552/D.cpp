#include <bits/stdc++.h>
using namespace std;
int t,n,i,a[22];
bool ok;
void rec(int l, int cnt, int cur) {
  if (cnt>0 && cur==0) {
    ok=true;
    return;
  }
  if (l==n) return;
  rec(l+1,cnt+1,cur+a[l]);
  if (ok) return;
  rec(l+1,cnt+1,cur-a[l]);
  if (ok) return;
  rec(l+1,cnt,cur);
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    ok=false;
    rec(0,0,0);
    puts(ok?"YES":"NO");
  }
  return 0;
}