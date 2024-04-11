#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,o,z,cnt,a[2];
vector<int> v[200200];
char s[200200];
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) a[s[i]-'0']++;
  m=a[0]-a[1];
  if (m<=0) { puts("-1"); return 0; }
  for (i=0; i<n; i++) if (s[i]=='0') {
    if (v[z%m].size()%2==1) { puts("-1"); return 0; }
    v[z%m].push_back(i);
    z++;
  } else if (s[i]=='1') {
    if (v[o%m].size()%2==0) { puts("-1"); return 0; }
    v[o%m].push_back(i);
    o++;
  }
  for (i=0; i<m; i++) {
    cnt=v[i].size();
    if (cnt%2==0) { puts("-1"); return 0; }
    for (j=1; j<cnt; j++) if (v[i][j]<=v[i][j-1]) { puts("-1"); return 0; }
  }
  printf("%d",m);
  for (i=0; i<m; i++) {
    cnt=v[i].size();
    printf("\n%d",cnt);
    for (j=0; j<cnt; j++) printf(" %d",v[i][j]+1);
  }
  return 0;
}