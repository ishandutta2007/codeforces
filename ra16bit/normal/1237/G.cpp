#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int n,m,i,j,cnt,cur,tot,best,w,iter,was[MX],a[MX],len[MX],nxt[MX],b[19][MX];
map<long long,vector<int>> all;
long long sc,s[MX];
void solve(int le, int ri, bool rev, long long fi) {
  if (le+m-1>ri) {
    if (le>=ri) return;
    int nle=(ri+n-m)%n;
    printf("%d %lld",nle,s[ri]-(rev?s[nle]:(s[le]-fi))+sc);
    for (int j=2; j<=m; j++) printf(" %d",sc);
    putchar('\n');
    return;
  }
  long long now=s[le+m-1]-s[le]+(rev?a[le-1]:fi);
  long long need=(rev?fi:0);
  if (now<need) {
    solve(le+m-1,ri,true,a[le+m-2]+need-now);
    printf("%d %d",(le-1)%n,(rev?fi:0)+sc);
    for (int j=2; j<=m; j++) printf(" %d",sc);
    putchar('\n');
  } else {
    printf("%d %d",(le-1)%n,(rev?fi:0)+sc);
    for (int j=2; j<m; j++) printf(" %d",sc);
    printf(" %d\n",now-need+sc);
    solve(le+m-1,ri,false,now-need);
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    sc+=a[i];
  }
  sc/=n;
  for (i=0; i<n; i++) a[n+i]=a[i]=a[i]-sc;
  all[0].push_back(0);
  for (i=1; i<=2*n; i++) {
    s[i]=s[i-1]+a[i-1];
    all[s[i]].push_back(i);
  }
  if (m==2) {
    for (auto it=all.begin(); it!=all.end(); ++it) {
      cnt=it->second.size();
      if (cnt/2>best) {
        best=cnt/2;
        w=it->second[0];
      }
    }
    printf("%d\n",n-best);
    cur=w;
    for (i=w+1; i<=n+w; i++) if (s[i]==s[w]) {
      solve(cur+1,i,false,a[cur]);
      cur=i;
    }
    return 0;
  }
  for (auto it=all.begin(); it!=all.end(); ++it) {
    cnt=it->second.size();
    ++iter;
    for (j=cnt-1; j>=0; j--) {
      cur=it->second[j]%(m-1);
      was[cur]=iter;
      nxt[cur]=it->second[j];
      if (++cur==m-1) cur=0;
      b[0][it->second[j]]=(was[cur]!=iter)?n*2+1:nxt[cur];
    }
  }
  b[0][2*n+1]=2*n+1;
  for (j=1; j<19; j++) for (i=0; i<=2*n+1; i++) b[j][i]=b[j-1][b[j-1][i]];
  for (i=0; i<n; i++) {
    cur=i;
    tot=0;
    for (j=18; j>=0; j--) if (b[j][cur]<i+n) {
      cur=b[j][cur];
      tot+=(1<<j);
    }
    //printf("i=%d tot=%d\n",i,tot);
    if (tot>best) { best=tot; w=i; }
  }
  printf("%d\n",(n-best+m-3)/(m-1));
  cur=w;
  for (i=b[0][w]; i<=n+w; i=b[0][i]) {
    solve(cur+1,i,false,a[cur]);
    cur=i;
  }
  solve(cur+1,n+w,false,a[cur]);
  return 0;
}