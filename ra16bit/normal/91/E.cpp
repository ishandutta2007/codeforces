#include <cstdio>
#include <algorithm>
using namespace std;
const int zz=300,ww=100000/zz;
struct walrus { int first,second,third; } c[ww+5][zz+5];
int i,j,n,m,e,ee,l,r,ll,rr,tt,p,le,ri,h,a[100100],b[100100],k[ww+5],t[ww+5][zz+5];
long long xx,yy,cur,res;
bool cmp(walrus a, walrus b) {
  if (a.first!=b.first) return a.first<b.first;
  return a.second>b.second;
}
long long go(int x, long long y, int z) { return y*z+x; }
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d%d",&a[i],&b[i]);
  for (i=p=0; i<n; i+=zz,p++) {
    for (e=j=0; i+j<n && j<zz; j++) { c[p][j].first=b[i+j]; c[p][j].second=a[i+j]; c[p][j].third=i+j; e++; }
    sort(c[p],c[p]+e,cmp); ee=0;
    for (j=1; j<e; j++) {
      while (ee>=0 && go(c[p][j].second,c[p][j].first,t[p][ee])>=go(c[p][ee].second,c[p][ee].first,t[p][ee])) ee--;
      if (ee>=0 && c[p][j].first==c[p][ee].first) continue;
      c[p][++ee]=c[p][j];
      if (ee>0) {
        xx=c[p][ee-1].second-c[p][ee].second;
        yy=c[p][ee].first-c[p][ee-1].first;
        t[p][ee]=xx/yy;
        if (xx%yy!=0) t[p][ee]++;
      } else t[p][ee]=0;
    }
    k[p]=ee;
  }
  while (m--) {
    scanf("%d%d%d",&l,&r,&tt); l--; r--;
    //int L=l,R=r;
    ll=l%zz; p=l; res=0;
    while (l<=r && ll!=zz) {
      cur=b[l];
      cur=cur*tt+a[l];
      if (cur>res) { res=cur; p=l; }
      l++; ll++;
    }
    rr=r%zz;
    while (l<=r && rr!=-1) {
      cur=b[r];
      cur=cur*tt+a[r];
      if (cur>res) { res=cur; p=r; }
      r--; rr--;
    }
    j=l/zz;
    e=(r+1)/zz;
    //printf("%d %d %d\n",j,e,p);
    //printf("%d %d %d===\n",tt,L,R);
    for (; j<e; j++) {
      //for (int q=0; q<=k[j]; q++) printf("%d %d: %d %d %d %d\n",j,q,c[j][q].first,c[j][q].second,c[j][q].third,t[j][q]);
      le=0; ri=k[j];
      while (le<ri) {
        h=(le+ri+1)/2;
        if (t[j][h]>tt) ri=h-1; else le=h;
      }
      cur=c[j][ri].first;
      cur=cur*tt+c[j][ri].second;
      if (cur>res) { res=cur; p=c[j][ri].third; }
    }
    //for (j=L; j<=R; j++) {
      //cur=b[j];
      //cur=cur*tt+a[j];
      //if (cur>res) printf("Wrong %d %d %I64d %I64d %d\n",m,j,cur,res,p);
    //}
    printf("%d\n",p+1);
  }
  return 0;
}