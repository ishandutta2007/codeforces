#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int i,j,x,n,best,b,cnt,cur,nxt,res,u[2*MX],fi[2*MX],fw[2*MX];
vector<int> w[MX];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    w[x].push_back(i);
  }
  for (i=best=1; i<=n; i++) if (w[i].size()>w[best].size()) {
    best=i; cnt=1;
  } else if (w[i].size()==w[best].size()) ++cnt;
  if (cnt>1) { printf("%d\n",n); return 0; }
  res=0;
  for (i=1; i<=n; i++) if (w[i].size() && i!=best) {
    u[MX]=i;
    fi[MX]=-1;
    fw[MX]=-1;
    for (j=0; j<w[i].size(); j++) {
      cur=w[i][j];
      cnt=upper_bound(w[best].begin(),w[best].end(),cur)-w[best].begin();
      b=j+1-cnt+MX;
      if (u[b-1]!=i && cnt>0) {
        u[b-1]=i;
        fi[b-1]=w[best][cnt-1];
        fw[b-1]=cnt-1;
      }
      if (u[b]!=i) {
        u[b]=i;
        if (b>MX) {
          fi[b]=cur;
          fw[b]=-1;
        } else {
          fw[b]=fw[b-1]-1;
          fi[b]=w[best][fw[b]];
        }
      }
      nxt=(j+1<w[i].size())?w[i][j+1]:n;
      while (cnt<w[best].size() && w[best][cnt]<nxt) {
        if (u[b]!=i) break;
        res=max(res,w[best][cnt]-1-fi[b]);
        --b;
        ++cnt;
      }
      if (u[b]==i) res=max(res,nxt-1-fi[b]);
    }
  }
  printf("%d\n",res);
  return 0;
}