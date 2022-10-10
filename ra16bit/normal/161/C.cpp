#include <cstdio>
#include <algorithm>
using namespace std;
int la,ra,lb,rb,x,y,wx,wy,lla,rra,llb,rrb,best,i,p;
void solve(int l, int r, int &x, int &w) {
  int p=0,z=0,i;
  for (i=1; ; i=2*i+1,z++) if (r-(r&i)<l) break; else p=i;
  x=r-(r&p);
  w=z;
}
int ints(int la, int ra, int lb, int rb) {
//printf("ints [%d %d] [%d %d]\n",la,ra,lb,rb);
  int x=max(la,lb),y=min(ra,rb);
//  printf("=%d\n",max(0,y-x+1));
  return max(0,y-x+1);
}
//const char s[32]={0,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,5,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1};
int main() {
  scanf("%d%d%d%d",&la,&ra,&lb,&rb);
  //for (la=1; la<=31; la++) for (ra=la; ra<=31; ra++) for (lb=1; lb<=31; lb++) for (rb=lb; rb<=31; rb++) {
  solve(la,ra,x,wx);
  solve(lb,rb,y,wy);
  //printf("%d %d %d %d\n",x,wx,y,wy);
  if (wx==wy) best=ints(la,ra,x-y+lb,x-y+rb);
    else if (wx<wy) best=max(ints(y-(1<<wx)-x+la,y-(1<<wx)-x+ra,lb,rb),ints(y+(1<<wx)-x+la,y+(1<<wx)-x+ra,lb,rb));
      else best=max(ints(la,ra,x-(1<<wy)-y+lb,x-(1<<wy)-y+rb),ints(la,ra,x+(1<<wy)-y+lb,x+(1<<wy)-y+rb));
  for (i=min(wx,wy); i>0; i--) {
    p=1<<i;
    lla=max(1,p-x+la);
    rra=min(p-1,ra-x);
    llb=max(1,p-y+lb);
    rrb=min(p-1,rb-y);
    best=max(best,ints(lla,p-1,llb,p-1));
    best=max(best,ints(lla,p-1,1,rrb));
    best=max(best,ints(1,rra,llb,p-1));
    best=max(best,ints(1,rra,1,rrb));
  }
  printf("%d\n",best);
  /*int tbest=0;
  for (int i=la; i<=ra; i++) for (int j=lb; j<=rb; j++) {
    int cur;
    for (cur=0; i+cur<=ra && j+cur<=rb; cur++) if (s[i+cur]!=s[j+cur]) break;
    tbest=max(tbest,cur);
  }
  if (best!=tbest) printf("[%d %d] [%d %d] = %d %d\n",la,ra,lb,rb,tbest,best);
  }*/
  return 0;
}