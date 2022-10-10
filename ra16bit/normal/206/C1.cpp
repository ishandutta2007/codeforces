#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MX=7070,MB=26;
int n,x,y,i,j,k,e,v,cur,num[3],N[3],was[MX],wh[MX],where[3][MX],a[3][MX],st[3][MX],cnt[3][MX],ocn[3][MX],p[3][MX],c[3][MX],b[3][MX][MB];
long long tot[MX],cnt1,cnt2,old;
vector <int> all;
char s[5];
int main() {
  scanf("%d",&n);
  tot[0]=1;
  num[1]=N[1]=where[1][1]=1;
  num[2]=N[2]=where[2][1]=1;
  for (i=1; i<=n; i++) {
    scanf("%d%d",&x,&y);
    if (x==2) tot[i]=1;
    was[i]=x;
    y=where[x][y];
    scanf("%s",s);
    cur=s[0]-'a';
    if (b[x][y][cur]==0) {
      b[x][y][cur]=++num[x];
      p[x][num[x]]=y;
      c[x][num[x]]=cur;
    }
    v=b[x][y][cur];
    where[x][++N[x]]=v;
    wh[i]=v;
    cnt[x][v]++;
  }
  for (i=1; i<=2; i++) for (j=1; j<=num[i]; j++) {
    cnt[i][j]+=cnt[i][j-1];
    ocn[i][j]=cnt[i][j];
    st[i][j]=cnt[i][j-1]+1;
    //printf("%d %d: %d %d\n",i,j,st[i][j],cnt[i][j]);
  }
  for (i=1; i<=n; i++) a[was[i]][ocn[was[i]][wh[i]]--]=i;
  /*for (i=1; i<=2; i++) {
    printf("%d === %d\n",i,num[i]);
    for (j=1; j<=num[i]; j++) {
      printf("%d (%d %c)\n",j,p[i][j],char('a'+c[i][j]));
      for (e=st[i][j]; e<=cnt[i][j]; e++) printf("%d ",a[i][e]); puts("times");
      for (k=0; k<26; k++) if (b[i][j][k]) printf("%c->%d\n",char('a'+k),b[i][j][k]);
    }
  }*/
  all.reserve(n);
  for (i=1; i<=num[2]; i++) {
    all.clear();
    for (j=st[2][i]; j<=cnt[2][i]; j++) all.push_back(a[2][j]);
    //printf("%d:\n",i);
    for (j=1, k=i; k!=1; k=p[2][k]) {
      //printf("%d %d\n",j,k);
      cur=c[2][k];
      if (b[1][j][cur]==0) break;
      //puts("ok");
      j=b[1][j][cur];
      for (e=st[1][j]; e<=cnt[1][j]; e++) all.push_back(a[1][e]);
    }
    sort(all.begin(),all.end());
    //for (int i=0; i<all.size(); i++) printf("%d, ",all[i]); puts("~");
    for (cnt1=cnt2=j=0; j<all.size(); j++) {
      old=cnt1*cnt2;
      if (was[all[j]]==1) cnt1++; else cnt2++;
      tot[all[j]]+=cnt1*cnt2-old;
    }
  }
  for (i=1; i<=n; i++) printf("%I64d\n",(tot[i]+=tot[i-1]));
  return 0;
}