#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,j,cur,r,ans[111*111*3*3*2];
vector<pair<int,int>> v[2];
char s[111][111];
void go(int i, int j) {
  for (int k=0; k<2; k++) v[k].clear();
  for (int x=0; x<2; x++) for (int y=0; y<2; y++) v[s[i+x][j+y]-'0'].push_back({i+x,j+y});
}
void solve(int i, int j) {
  go(i,j);
  if (v[1].size()==4) {
    for (int k=0; k<3; k++) {
      ans[r++]=v[1][k].first;
      ans[r++]=v[1][k].second;
      s[ans[r-2]][ans[r-1]]^=1;
    }
    go(i,j);
  }
  if (v[1].size()==1) {
    ans[r++]=v[1][0].first;
    ans[r++]=v[1][0].second;
    s[ans[r-2]][ans[r-1]]^=1;
    for (int k=0; k<2; k++) {
      ans[r++]=v[0][k].first;
      ans[r++]=v[0][k].second;
      s[ans[r-2]][ans[r-1]]^=1;
    }
    go(i,j);
  }
  if (v[1].size()==2) {
    ans[r++]=v[1][0].first;
    ans[r++]=v[1][0].second;
    s[ans[r-2]][ans[r-1]]^=1;
    for (int k=0; k<2; k++) {
      ans[r++]=v[0][k].first;
      ans[r++]=v[0][k].second;
      s[ans[r-2]][ans[r-1]]^=1;
    }
    go(i,j);
  }
  if (v[1].size()==3) {
    for (int k=0; k<3; k++) {
      ans[r++]=v[1][k].first;
      ans[r++]=v[1][k].second;
      s[ans[r-2]][ans[r-1]]^=1;
    }
  }
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) scanf("%s",s[i]);
    for (r=i=0; i+1<n; i++) {
      for (j=0; j+1<m; j++) if (s[i][j]=='1' && (i!=n-2 || j!=m-2)) {
        ans[r++]=i;
        ans[r++]=j;
        s[ans[r-2]][ans[r-1]]^=1;
        cur=1;
        if (s[i][j+1]=='1') {
          ans[r++]=i;
          ans[r++]=j+1;
          s[ans[r-2]][ans[r-1]]^=1;
          ++cur;
        }
        if (s[i+1][j]=='1' || cur==1) {
          ans[r++]=i+1;
          ans[r++]=j;
          s[ans[r-2]][ans[r-1]]^=1;
          ++cur;
        }
        if (cur<3) {
          ans[r++]=i+1;
          ans[r++]=j+1;
          s[ans[r-2]][ans[r-1]]^=1;
          ++cur;
        }
      }
      if (i<n-2 && s[i][m-1]=='1') {
        ans[r++]=i;
        ans[r++]=m-1;
        s[ans[r-2]][ans[r-1]]^=1;
        ans[r++]=i+1;
        ans[r++]=m-1;
        s[ans[r-2]][ans[r-1]]^=1;
        ans[r++]=i+1;
        ans[r++]=m-2;
        s[ans[r-2]][ans[r-1]]^=1;
      }
    }
    i=n-1;
    for (j=0; j+2<m; j++) if (s[i][j]=='1') {
      ans[r++]=i;
      ans[r++]=j;
      s[ans[r-2]][ans[r-1]]^=1;
      ans[r++]=i;
      ans[r++]=j+1;
      s[ans[r-2]][ans[r-1]]^=1;
      ans[r++]=i-1;
      ans[r++]=(s[i-1][j]=='1')?j:(j+1);
      s[ans[r-2]][ans[r-1]]^=1;
    } else if (s[i-1][j]=='1') {
      ans[r++]=i-1;
      ans[r++]=j;
      s[ans[r-2]][ans[r-1]]^=1;
      ans[r++]=i;
      ans[r++]=j+1;
      s[ans[r-2]][ans[r-1]]^=1;
      ans[r++]=i-1;
      ans[r++]=j+1;
      s[ans[r-2]][ans[r-1]]^=1;
    }
    solve(n-2,m-2);
    printf("%d\n",r/6);
    for (i=0; i<r; ) for (j=0; j<6; i++, j++) printf("%d%c",ans[i]+1,(j==5)?'\n':' ');
  }
  return 0;
}