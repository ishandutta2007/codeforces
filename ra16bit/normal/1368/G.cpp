#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
struct Node {
  int add,cnt;
} b[525525];
int n,m,num,T,i,j,cur,x,y,z,c[MX],t[MX],lst[MX];
vector<int> g[2][MX];
bool rt[2][MX];
char s[MX];
long long res;
void mdf(int i, int L, int R, int le, int ri, int v) {
  if (L==le && R==ri) b[i].add+=v; else {
    int h=(L+R)/2;
    if (le<=h) mdf(i*2,L,h,le,min(ri,h),v);
    if (ri>h) mdf(i*2+1,h+1,R,max(le,h+1),ri,v);
  }
  if (b[i].add==0) {
    b[i].cnt=(L==R)?0:(b[i*2].cnt+b[i*2+1].cnt);
  } else b[i].cnt=R-L+1;
}
void dfs(int i) {
  t[i]=++T;
  for (int j=0; j<g[0][i].size(); j++) dfs(g[0][i][j]);
  lst[i]=T;
}
void solve(int i) {
  mdf(1,1,T,t[i],lst[i],1);
  res+=b[1].cnt;
  for (int j=0; j<g[1][i].size(); j++) solve(g[1][i][j]);
  mdf(1,1,T,t[i],lst[i],-1);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%s",s+i*m);
    for (j=0; j<m; j++) {
      cur=i*m+j;
      if (s[cur]=='D') c[cur]=c[cur-m]; else
        if (s[cur]=='R') c[cur]=c[cur-1]; else {
          c[cur]=++num;
          rt[0][num]=true;
          rt[1][num]=true;
        }
    }
  }
  for (i=0; i<n*m; i++) {
    x=i/m; y=i%m; z=(x+y)&1;
    if (x>0 && s[i-m]=='D') { g[z][c[i]].push_back(c[i-m]); rt[z][c[i-m]]=false; }
    if (x+1<n && s[i+m]=='U') { g[z][c[i]].push_back(c[i+m]); rt[z][c[i+m]]=false; }
    if (y>0 && s[i-1]=='R') { g[z][c[i]].push_back(c[i-1]); rt[z][c[i-1]]=false; }
    if (y+1<m && s[i+1]=='L') { g[z][c[i]].push_back(c[i+1]); rt[z][c[i+1]]=false; }
  }
  for (i=1; i<=num; i++) if (rt[0][i]) dfs(i);
  for (i=1; i<=num; i++) if (rt[1][i]) solve(i);
  printf("%I64d\n",res);
  return 0;
}