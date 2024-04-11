#include <bits/stdc++.h>
using namespace std;
const int MX=50100;
int t,num,n,i,cur,mx,cnt[MX*2];
pair<int,int> r[MX*20];
void add(int x, int y) {
  r[num].first=x;
  r[num].second=y;
  ++num;
  --cnt[x];
  --cnt[y];
  ++cnt[x+y];
  ++cnt[x-y];
  mx=max(mx,x+y);
}
void solve(int m, int n) {
  if (n<=2) return;
  int pw=0,le;
  while ((1<<pw)<n) ++pw;
  pw=(1<<(pw-1));
  if (n==pw*2) --n;
  for (int i=pw+1; i<=n; i++) {
    le=pw-(i-pw);
    add(m*i,m*le);
  }
  solve(m,le-1);
  solve(m*2,n-pw);
}
int main() {
  scanf("%d",&t);
  while (t--) {
    for (i=1; i<=mx; i++) cnt[i]=0;
    scanf("%d",&n); mx=n;
    num=0;
    for (i=1; i<=n; i++) ++cnt[i];
    solve(1,n);
    if (cnt[0]==0) {
      for (i=1; i<=mx; i++) if (cnt[i]>1) {
        add(i,i);
        mx=max(mx,i*2);
        break;
      }
      if (i>mx) { puts("-1"); continue; }
    }
    
    for (i=1; i<mx; i++) while (cnt[i]>0) {
      add(i,0);
      add(i,i);
    }
    for (i=0; i<cnt[0]; i++) add(mx,0);
    printf("%d\n",num);
    for (i=0; i<num; i++) printf("%d %d\n",r[i].first,r[i].second);
  }
  return 0;
}