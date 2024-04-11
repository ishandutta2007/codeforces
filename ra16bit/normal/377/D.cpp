#include <cstdio>
#include <vector>
using namespace std;
const int MX=100010,LEN=3*MX;
struct Node { int add,mx,w; } a[LEN*4];
int n,i,j,res,wl,wr,lc[MX],vc[MX],rc[MX];
vector<int> mid[LEN],rig[LEN];
void add(int i, int L, int R, int l, int r, int v) {
  if (L==l && R==r) {
    a[i].add+=v;
    a[i].mx+=v;
    if (a[i].w==0) a[i].w=L;
    return;
  }
  int h=(L+R)/2;
  if (l<=h) add(i*2,L,h,l,min(h,r),v);
  if (r>h) add(i*2+1,h+1,R,max(h+1,l),r,v);
  if (a[i*2].mx>a[i*2+1].mx) {
    a[i].mx=a[i*2].mx; a[i].w=a[i*2].w;
  } else {
    a[i].mx=a[i*2+1].mx; a[i].w=a[i*2+1].w;
  }
  a[i].mx+=a[i].add;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%d",&lc[i],&vc[i],&rc[i]);
    mid[vc[i]].push_back(i);
    rig[rc[i]].push_back(i);
  }
  for (i=1; i<LEN; i++) {
    for (j=0; j<mid[i].size(); j++) add(1,1,LEN-1,lc[mid[i][j]],i,1);
    if (a[1].mx>res) { res=a[1].mx; wl=a[1].w; wr=i; }
    for (j=0; j<rig[i].size(); j++) add(1,1,LEN-1,lc[rig[i][j]],vc[rig[i][j]],-1);
  }
  printf("%d\n",res);
  for (i=j=0; i<n; i++) if (lc[i]<=wl && vc[i]>=wl && vc[i]<=wr && rc[i]>=wr)
    printf("%d%c",i+1,(++j==res)?'\n':' ');
  return 0;
}