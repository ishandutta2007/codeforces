#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,i;
pair<int,int> a[MX],b[MX];
set<int> was;
char r[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) { scanf("%d",&a[i].first); a[i].second=i; }
    for (i=0; i<n; i++) { scanf("%d",&b[i].first); b[i].second=i; r[i]='0'; }
    sort(a,a+n);
    sort(b,b+n);
    r[n]=0;
    was.clear();
    for (i=n-1; i>=0; i--) {
      was.insert(a[i].second);
      was.insert(b[i].second);
      if (was.size()==n-i) break;
    }
    for (; i<n; i++) r[a[i].second]='1';
    puts(r);
  }
  return 0;
}