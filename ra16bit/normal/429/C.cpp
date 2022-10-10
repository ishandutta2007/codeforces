#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,e,a[26];
bool was[26],q;
void rec(int l) {
  if (a[l]==1) {
    int c=0;
    for (int j=l+1; j<n; j++) c+=a[j]-1;
    if (c==e) q=true;
    return;
  }
  for (int i=l+1; i<n; i++) if (a[i]>=a[l]+1) {
    if (a[i]==a[l]+1 && !was[i]) continue;
    a[i]-=a[l];
    bool ow=was[i];
    was[i]=true;
    rec(l-1);
    if (q) return;
    was[i]=ow;
    a[i]+=a[l];
  }
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  if (n==1 && a[0]==1) { puts("YES"); return 0; }
  sort(a,a+n);
  for (e=0; e<n; e++) if (a[e]!=1) break;
  if (e==n || e*2-1<n || a[e]==2) { puts("NO"); return 0; }
  rec(n-2);
  puts(q?"YES":"NO");
  return 0;
}