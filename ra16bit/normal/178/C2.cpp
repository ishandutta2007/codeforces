#include <cstdio>
#include <map>
using namespace std;
int h,m,t,tot,i,j,x,y,pos,left,l,r,prev[200200],next[200200],a[200200],w[200200];
long long res;
map <int, int> M;
char s[7];
int sum(int l, int r) {
  int s=0;
  for (int j=r  ; j>0; j&=j-1) s+=a[j];
  for (int j=l-1; j>0; j&=j-1) s-=a[j];
  return s;
}
int main() {
  scanf("%d%d%d",&h,&m,&t);
  for (i=0; i<h; i++) if (w[i]==0) {
    prev[tot+1]=tot+1;
    for (j=i; w[j]==0; j=(j+m)%h) w[j]=++tot;
    next[tot]=tot;
  }
  for (i=1; i<=tot; i++) if (prev[i]==0) prev[i]=prev[i-1];
  for (i=tot; i>=1; i--) if (next[i]==0) next[i]=next[i+1];
  while (t--) {
    scanf("%s",s);
    if (s[0]=='+') {
      scanf("%d%d",&x,&y);
      pos=w[y];
      l=prev[pos];
      r=next[pos];
      if (sum(pos,r)==r-pos+1) {
        res+=r-pos+1;
        r=pos-1;
      } else l=pos;
      left=l;
      while (l<r) {
        h=(l+r)/2;
        if (sum(left,h)<h-left+1) r=h; else l=h+1;
      }
      res+=r-left;
      M[x]=r;
      for (x=r; x<=tot; x=(x<<1)-(x&(x-1))) a[x]++;
    } else {
      scanf("%d",&x);
      for (x=M[x]; x<=tot; x=(x<<1)-(x&(x-1))) a[x]--;
    }
  }
  printf("%I64d\n",res);
  return 0;
}