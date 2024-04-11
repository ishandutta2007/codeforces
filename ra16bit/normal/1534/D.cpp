#include <bits/stdc++.h>
using namespace std;
const int MX=2020;
int n,i,w,a[MX],d[MX],cnt[2];
vector<int> g[MX];
void ask(int x) {
  printf("? %d\n",x);
  fflush(stdout);
  for (int i=1; i<=n; i++) {
    scanf("%d",&d[i]);
    if (i>1 && d[i]==1) g[x].push_back(i);
  }
}
int main() {
  scanf("%d",&n);
  ask(1);
  for (i=1; i<=n; i++) {
    a[i]=d[i];
    if (i>1) ++cnt[a[i]%2];
  }
  w=int(cnt[0]>cnt[1]);
  for (i=2; i<=n; i++) if (a[i]%2==w) ask(i);
  puts("!");
  for (i=1; i<=n; i++) for (int x: g[i]) printf("%d %d\n",i,x);
  fflush(stdout);
  return 0;
}