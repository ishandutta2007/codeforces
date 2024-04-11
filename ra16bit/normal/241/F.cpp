#include <stdio.h>
#include <string.h>
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int n,m,cnt,i,j,X,Y,xs[28],ys[28],qx[104*104],qy[104*104],d[28][104][104],p[28][104][104];
char s[104][104],t[1111];
void bfs(int st) {
  int fi=0,fr=1,i,j,k,x,y;
  qx[0]=xs[st]; qy[0]=ys[st];
  d[st][xs[st]][ys[st]]=1;
  while (fi<fr) {
    x=qx[fi]; y=qy[fi++];
    for (k=0; k<4; k++) {
      i=x+dx[k];
      j=y+dy[k];
      if (s[i][j]=='#' || d[st][i][j]>0) continue;
      if (s[x][y]>='0' && s[x][y]<='9') d[st][i][j]=d[st][x][y]+s[x][y]-'0'; else d[st][i][j]=d[st][x][y]+1;
      p[st][i][j]=k;
      qx[fr]=i; qy[fr++]=j;
    }
  }
}
bool upd(int st, int x, int y) {
  int tm=d[st][x][y]-1;
  if (tm==cnt) {
    printf("%d %d\n",x,y);
    return true;
  }
  if (tm>cnt) {
    while (tm>=0) {
      int k=p[st][x][y];
      x-=dx[k];
      y-=dy[k];
      if (s[x][y]>='0' && s[x][y]<='9') tm-=s[x][y]-'0'; else tm--;
      if (tm<=cnt) {
        printf("%d %d\n",x,y);
        break;
      }
    }
    return true;
  }
  cnt-=tm;
  return false;
}
int main() {
  scanf("%d%d%d",&n,&m,&cnt);
  for (i=1; i<=n; i++) {
    scanf("%s",s[i]+1);
    for (j=1; j<=m; j++) if (s[i][j]>='a' && s[i][j]<='z') {
      xs[s[i][j]-'a']=i;
      ys[s[i][j]-'a']=j;
    }
  }
  for (i=0; i<=m+1; i++) { s[0][i]='#'; s[n+1][i]='#'; }
  for (i=0; i<=n+1; i++) { s[i][0]='#'; s[i][m+1]='#'; }
  scanf("%d%d",&xs[26],&ys[26]);
  for (i=0; i<=26; i++) if (xs[i]!=0) bfs(i);
  scanf("%s",t+1); 
  t[0]='a'+26;
  m=strlen(t);
  for (i=1; i<m; i++) if (upd(t[i-1]-'a',xs[t[i]-'a'],ys[t[i]-'a'])) return 0;
  scanf("%d%d",&X,&Y);
  if (upd(t[m-1]-'a',X,Y)) return 0;
  printf("%d %d\n",X,Y);
  return 0;
}