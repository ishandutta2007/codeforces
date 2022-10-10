#include <cstdio>
#include <vector>
using namespace std;
int n,m,q,i,j,k,cur,xa,ya,xb,yb,up[42],f[42][42],r[302010];
vector<int> all[42][42],w[42][42];
char s[42][42];
int main() {
  scanf("%d%d%d",&n,&m,&q);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=0; i<q; i++) {
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    xa--; ya--; xb--; yb--;
    all[xa][ya].push_back(xb*50*500000+yb*500000+i);
  }
  for (xa=0; xa<n; xa++) for (ya=0; ya<m; ya++) if (!all[xa][ya].empty()) {
    for (i=xa; i<n; i++) for (j=ya; j<m; j++) w[i][j].clear();
    for (j=ya; j<m; j++) up[j]=0;
    for (i=0; i<all[xa][ya].size(); i++) {
      yb=all[xa][ya][i]/500000;
      xb=yb/50;
      yb%=50;
      w[xb][yb].push_back(all[xa][ya][i]%500000);
    }
    for (i=xa; i<n; i++) for (j=ya; j<m; j++) {
      if (s[i][j]=='1') up[j]=0; else up[j]++;
      f[i][j]=0;
      if (i>xa) {
        f[i][j]+=f[i-1][j];
        if (j>ya) f[i][j]-=f[i-1][j-1];
      }
      if (j>ya) f[i][j]+=f[i][j-1];
      for (k=j, cur=up[j]; k>=ya && cur>0; k--) {
        cur=min(cur,up[k]);
        f[i][j]+=cur;
      }
      for (k=0; k<w[i][j].size(); k++) r[w[i][j][k]]=f[i][j];
    }
  }
  for (i=0; i<q; i++) printf("%d\n",r[i]);
  return 0;
}