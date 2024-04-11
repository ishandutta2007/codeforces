#include<cstdio>
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int a[8][8];
char s[10][10];
int rec(int cnt,int x,int y){
  //printf("%d %d\n",x,y);
  if(cnt==8)return 1;
  if(a[y][x]==1)return 0;
  if(y<1)return 1;
  int i,j;
  for(j=-1;j<2;j++){
    if(y+j+cnt>7||y+j+cnt<0)continue;
    for(i=-1;i<2;i++){
      if(x+i>7||x+i<0)continue;
      if(a[y+j][x+i]==1)continue;
      if(y+j==0)return 1;
      int r=rec(cnt+1,x+i,y+j-1);
      if(r>0)return 1;
    }
  }
  return 0;
}
int main(){
  REP(j,8)scanf("%s",s[j]);
  REP(j,8)REP(i,8){
    if(s[j][i]=='S')a[j][i]=1;
    else a[j][i]=0;
  }
  puts(rec(0,0,7)?"WIN":"LOSE");
}