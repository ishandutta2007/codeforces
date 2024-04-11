#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=30300;
const long long inf=2000000000000000000LL;
int t,n,m,q,i,j,k,le,ri,h,r,pos,nls,ngr,ans[7],p[MX];
long long cur,now,sta,f[MX][7],fls[MX*5][7],fgr[MX*5][7];
pii ls[MX*5],gr[MX*5];
bool cmpls(const pii& x, const pii& y) {
  if (x.first!=y.first) return x.first<y.first;
  return p[x.second]<p[y.second];
}
bool cmpgr(const pii& x, const pii& y) {
  if (x.first!=y.first) return x.first>y.first;
  return p[x.second]<p[y.second];
}
int main() {
  for (j=0; j<5; j++) f[0][j]=int(j==0);
  for (i=1; i<MX; i++) for (j=0; j<5; j++) {
    cur=f[i-1][j];
    if (j>0) {
      cur+=f[i-1][j-1];
      if (cur>inf) cur=inf;
    }
    f[i][j]=cur;
  }
  for (i=0; i<MX; i++) for (j=1; j<5; j++) {
    f[i][j]+=f[i][j-1];
    if (f[i][j]>inf) f[i][j]=inf;
  }
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d",&n,&m,&q);
    nls=ngr=0;
    for (i=1; i<=n; i++) {
      scanf("%d",&p[i]);
      //p[i]=i;
      for (j=1; j<i && j<=m; j++) if (p[i]<p[i-j]) ls[++nls]={i-j,i}; else gr[++ngr]={i-j,i};
    }
    sort(ls+1,ls+nls+1,cmpls);
    sort(gr+1,gr+ngr+1,cmpgr);
    for (j=0; j<=m; j++) fls[0][j]=fgr[0][j]=0;
    for (i=1; i<=nls; i++) for (j=0; j<=m; j++) {
      fls[i][j]=fls[i-1][j];
      k=ls[i].second-ls[i].first;
      if (k<=j) {
        fls[i][j]+=f[max(0,n-ls[i].second-1)][j-k];
        if (fls[i][j]>inf) fls[i][j]=inf;
      }
    }
    for (i=1; i<=ngr; i++) for (j=0; j<=m; j++) {
      fgr[i][j]=fgr[i-1][j];
      k=gr[i].second-gr[i].first;
      if (k<=j) {
        fgr[i][j]+=f[max(0,n-gr[i].second-1)][j-k];
        if (fgr[i][j]>inf) fgr[i][j]=inf;
      }
    }
    /*for (i=1; i<=nls; i++) printf("%d: (%d %d) [%d %d %d %d]\n",i,ls[i].first,ls[i].second,
    int(fls[i][1]),int(fls[i][2]),int(fls[i][3]),int(fls[i][4])); puts("ls");
    for (i=1; i<=ngr; i++) printf("(%d %d) [%d %d %d %d]\n",gr[i].first,gr[i].second,
    int(fgr[i][1]),int(fgr[i][2]),int(fgr[i][3]),int(fgr[i][4]));     puts("gr");*/
    //int it=0;
    while (q--) {
      scanf("%d%I64d",&k,&cur);
      //cur=max(1LL,fls[nls][m]+fgr[ngr][m]+1-q);
      //k=q%n+1;
      if (fls[nls][m]+fgr[ngr][m]+1<cur) { puts("-1"); continue; }
      j=m; pos=1; r=0;
      while (pos<n && j>0) {
        assert(cur>0);
        ls[0]={0,0};
        le=0; ri=nls+1;
        while (le<ri) {
          h=(le+ri)/2;
          if (ls[h].first<pos) le=h+1; else ri=h;
        }
        //printf("%d -ls-> [%d %d]\n",pos,ls[ri].first,ls[ri].second);
        if (ri<=nls) {
          sta=(le>0)?fls[le-1][j]:0;
          now=fls[nls][j]-sta;
        } else now=0;
        if (now+1==cur) break;
        if (cur<=now) {
          ri=nls;
          while (le<ri) {
            h=(le+ri)/2;
            if (fls[h][j]-sta<cur) le=h+1; else ri=h;
          }
          //printf("%d -ls-> [%d %d]\n",pos,ls[ri].first,ls[ri].second);
          cur-=fls[ri-1][j]-sta;
          for (int e=ls[ri].first; e<ls[ri].second; e++) ans[r++]=e;
          pos=ls[ri].second+1;
          j-=ls[ri].second-ls[ri].first;
          //printf(" new pos=%d j=%d cur=%I64d\n",pos,j,cur);
        } else {
          cur-=now+1;
          gr[0]={n,n};
          le=0; ri=ngr;
          while (le<ri) {
            h=(le+ri)/2+1;
            if (gr[h].first<pos) ri=h-1; else le=h;
          }
          le=0;
          while (le<ri) {
            h=(le+ri)/2;
            if (fgr[h][j]<cur) le=h+1; else ri=h;
          }
          assert(ri>0);
          if (ri>0) cur-=fgr[ri-1][j];
          for (int e=gr[ri].first; e<gr[ri].second; e++) ans[r++]=e;
          pos=gr[ri].second+1;
          j-=gr[ri].second-gr[ri].first;
          //printf(" new pos=%d j=%d cur=%I64d\n",pos,j,cur);
        }
      }
      for (i=0; i<r; i=j) {
        for (j=i; j<r && ans[j]==ans[i]+j-i; j++);
        if (k>=ans[i] && k<=ans[j-1]+1) {
          printf("%d\n",p[ans[j-1]+1-(k-ans[i])]);
          break;
        }
      }
      if (i>=r) printf("%d\n",p[k]);
    }
  }
  return 0;
}