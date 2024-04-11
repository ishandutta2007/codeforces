#include <stdio.h>
int i,j,x,y,cur,cnt,was[44];
char s[44],r[2][22];
int main() {
  scanf("%s",s);
  for (i=0; i<27; i++) {
    cur=s[i]-'A';
    if (was[cur]) {
      if (was[cur]==i) { puts("Impossible"); return 0; }
      cnt=(i-was[cur])/2;
      r[0][cnt]=s[i];
      for (j=was[cur], x=0, y=cnt; j<i; j++) {
        if (x) y++; else y--;
        if (y<0) { x=1; y=0; }
        r[x][y]=s[j];
      }
      for (j=i+1, x=0, y=cnt; j<27; j++) {
        if (x) y--; else y++;
        if (y>12) { x=1; y=12; }
        r[x][y]=s[j];
      }
      for (j=0; j<was[cur]-1; j++) {
        if (x) y--; else y++;
        if (y>12) { x=1; y=12; }
        r[x][y]=s[j];
      }
      for (j=0; j<2; j++) puts(r[j]);
      break;
    } else was[cur]=i+1;
  }
  return 0;
}