#include <bits/stdc++.h>
using namespace std;
const int MX=300300;
int n,m,i,j,cur,res,x,y,px,py,p[MX],rk[MX],sel[MX],cnt[MX];
vector<int> g[MX],pr[MX];
bool fix[MX],is_sel[MX],same[MX];
char s[MX];
int fs(int i) {
  if (i!=p[i]) {
    int pr=p[i];
    p[i]=fs(pr);
    same[i]=(same[i]==same[pr]);
  }
  return p[i];
}
void jnun(int px, int py, bool sx, bool sy, bool issame) {
//printf("join %d -> %d\n",px,py);
  res-=sel[px];
  res-=sel[py];
  p[px]=py;
  cnt[py]+=cnt[px];
  if ((sx==sy)==issame) {
    same[px]=(is_sel[px]==is_sel[py]);
    sel[py]+=sel[px];
  } else {
    same[px]=(is_sel[px]!=is_sel[py]);
    sel[py]+=cnt[px]-sel[px];
  }
  if (!fix[py] && sel[py]>cnt[py]-sel[py]) {
    sel[py]=cnt[py]-sel[py];
    is_sel[py]=!is_sel[py];
  }
  //printf(" same=%d, is_sel=%d, sel=%d, cnt=%d\n",same[px],is_sel[py],sel[py],cnt[py]);
  if (rk[px]==rk[py]) ++rk[py];
  res+=sel[py];
}
int main() {
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  for (i=0; i<m; i++) {
    scanf("%d",&j);
    while (j--) {
      scanf("%d",&x);
      g[x-1].push_back(i);
    }
    p[i]=i;
    sel[i]=0;
    cnt[i]=1;
    same[i]=true;
  }
  for (i=0; i<n; i++) {
    if (g[i].size()==2) {
      x=g[i][0]; px=fs(x);
      y=g[i][1]; py=fs(y);
      //printf("check %d %d\n",x,y);
      if (px!=py) {
        if ((rk[px]<rk[py] || fix[py]) && !fix[px]) {
          jnun(px,py,is_sel[px]==same[x],is_sel[py]==same[y],s[i]=='1');
        } else {
          jnun(py,px,is_sel[py]==same[y],is_sel[px]==same[x],s[i]=='1');
        }
      }
    }
    if (g[i].size()==1) {
      cur=fs(g[i][0]);
      if (!fix[cur]) {
        //printf("fix %d\n",cur);
        fix[cur]=true;
        if ((is_sel[cur]==same[g[i][0]])==(s[i]=='1')) {
          res-=sel[cur];
          is_sel[cur]=!is_sel[cur];
          sel[cur]=cnt[cur]-sel[cur];
          //printf(" rev %d | %d %d %d\n",cur,is_sel[cur],sel[cur],cnt[cur]);
          res+=sel[cur];
        }
      }
    }
    printf("%d\n",res);
  }
  return 0;
}