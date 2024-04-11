#include <cstdio>
#include <vector>
using namespace std;
const int MX=300021;
int n,i,x,y,b[MX][26],a[MX],r[MX],res,cnt;
vector<int> g[MX];
char s[MX];
void merge(int i, int j) {
  for (int c=0; c<26; c++) if (b[j][c]) {
    if (b[i][c]) {
      r[i]-=r[b[i][c]];
      merge(b[i][c],b[j][c]);
      r[i]+=r[b[i][c]];
    } else {
      b[i][c]=b[j][c];
      r[i]+=r[b[i][c]];
    }
  }
}
int dfs(int i, int p) {
  r[i]=1;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    dfs(k,i);
    int c=s[k-1]-'a';
    if (b[i][c]==0) {
      b[i][c]=k;
      r[i]+=r[k];
    } else {
      r[i]-=r[b[i][c]];
      merge(b[i][c],k);
      r[i]+=r[b[i][c]];
    }
  }
  if (r[i]+a[i]>res) { res=r[i]+a[i]; cnt=0; }
  if (r[i]+a[i]==res) cnt++;
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  scanf("%s",s);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,0);
  printf("%d\n%d\n",res,cnt);
  return 0;
}