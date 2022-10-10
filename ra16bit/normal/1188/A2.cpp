#include <bits/stdc++.h>
using namespace std;
int n,t,i,x,y,z,a[1010],c[1010],fi[1010],lst[1010];
vector<int> g[1010],f[1010],res[3];
void dfs(int i, int p, int pe) {
//printf("dfs %d %d %d\n",i,p,pe);
  fi[i]=t;
  if (g[i].size()==1) {
    c[t]=pe;
    a[t++]=i;
  } else {
    int prev=-1,frs=-1,frse=0,lstv=0;
    for (int j=0; j<g[i].size(); j++) {
      int k=g[i][j];
      if (k==p) continue;
      dfs(k,i,f[i][j]);
      if (frs==-1) { frs=k; frse=f[i][j]; continue; }
      if (prev!=-1) {
        int jp=fi[prev],jc=fi[k],lp=lst[prev],lc=lst[k];
        lstv=f[i][j];
        while (jp<lp) {
          while (jp+1<lp && c[jp]==0) jp++; 
          while (jc+1<lc && c[jc]==0) jc++;
          int vp=(c[jp]<0)?-c[jp]:c[jp];
          int vc=(c[jc]<0)?-c[jc]:c[jc];
          int cur=(vp<vc || jc+1==lc)?c[jp]:c[jc];
          if (cur!=0) {
            res[0].push_back(a[jp]);
            res[1].push_back(a[jc]);
            res[2].push_back(cur);
            c[jp]-=cur;
            c[jc]-=cur;
            lstv-=cur;
            //printf("lstv(%d) -= %d = %d\n",i,cur,lstv);
          }
          if (c[jp]==0) jp++; else if (c[jc]==0) jc++;
        }
      } else lstv=f[i][j];
      prev=k;
    }
    if (prev!=-1) {
    //printf("%d: %d %d\n",i,lstv,frse);
      lstv=(lstv-pe+frse)/2;
      //printf("=%d (%d %d)\n",lstv,pe,frse);
      int jp=fi[frs],jc=fi[prev],lp=lst[frs],lc=lst[prev];
      while (jp+1<lp || jc+1<lc) {
        while (jp+1<lp && c[jp]==0) jp++; 
        while (jc+1<lc && c[jc]==0) jc++;
        int vp=(c[jp]<0)?-c[jp]:c[jp];
        int vc=(c[jc]<0)?-c[jc]:c[jc];
        int cur=(vp<vc)?c[jp]:c[jc];
        if (jc+1==lc) cur=c[jp];
        if (jp+1==lp) cur=c[jc];
        if (cur!=0) {
          res[0].push_back(a[jp]);
          res[1].push_back(a[jc]);
          res[2].push_back(cur);
          //printf("connect %d %d %d\n",a[jp],a[jc],cur);
          c[jp]-=cur;
          c[jc]-=cur;
          lstv-=cur;
        }
        if (c[jp]==0 && jp+1!=lp) jp++;
        if (c[jc]==0 && jc+1!=lc) jc++;
      }
      //printf("lstv = %d\n",lstv);
      if (lstv!=0) {
        res[0].push_back(a[jp]);
        res[1].push_back(a[jc]);
        res[2].push_back(lstv);
        c[jp]-=lstv;
        c[jc]-=lstv;
      }
    }
  }
  lst[i]=t;
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    /*x=i+1;
    y=(i+1)/2;
    z=2*max(i,2);*/
    if (n==2) {
      puts("YES");
      if (z) {
        puts("1");
        printf("%d %d %d\n",x,y,z);
        return 0;
      } else puts("0");
    }
    g[x].push_back(y); f[x].push_back(z);
    g[y].push_back(x); f[y].push_back(z);
  }
  for (i=1; i<=n; i++) if (g[i].size()==2 && f[i][0]!=f[i][1]) {
    puts("NO");
    return 0;
  }
  for (i=1; i<=n; i++) if (g[i].size()==1) {
    x=g[i][0];
    dfs(x,i,f[i][0]);
    for (y=fi[x]; y<=lst[x]; y++) if (c[y]!=0) {
      res[0].push_back(i);
      res[1].push_back(a[y]);
      res[2].push_back(c[y]);
    }
    break;
  }
  puts("YES");
  printf("%d\n",int(res[0].size()));
  for (i=0; i<res[0].size(); i++) printf("%d %d %d\n",res[0][i],res[1][i],res[2][i]);
  return 0;
}