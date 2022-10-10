#include <cstdio>
#include <vector>
using namespace std;
const int md[2]={1000000007,1000000009};
int n,m,i,j,c,d,h[2][26],cur[2][26],a[200200][2][26];
char s[200200],t[200200];
long long st[2][200200];
vector<int> r;
int main() {
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  scanf("%s",t);
  for (j=0; j<2; j++) for (st[j][0]=i=1; i<=n; i++)
    st[j][i]=(st[j][i-1]*3LL)%md[j];
  for (j=0; j<2; j++) for (c=0; c<26; c++) for (i=0; i<m; i++) {
    h[j][c]=(h[j][c]*3LL+1+int('a'+c==t[i]))%md[j];
  }
  for (i=0; i<n; i++) {
    for (j=0; j<2; j++) for (c=0; c<26; c++) {
      a[i][j][c]=(a[i-1][j][c]*3LL+1+int('a'+c==s[i]))%md[j];
      if (i>=m-1) {
        cur[j][c]=a[i][j][c];
        if (i>=m) {
          cur[j][c]-=(a[i-m][j][c]*st[j][m])%md[j];
          if (cur[j][c]<0) cur[j][c]+=md[j];
        }
      }
    }
    if (i>=m-1) {
    for (c=0; c<26; c++) {
      for (j=0; j<2; j++) if (h[j][c]!=cur[j][c]) break;
      if (j<2) {
        for (d=0; d<26; d++) {
          for (j=0; j<2; j++) if (h[j][d]!=cur[j][c] || cur[j][d]!=h[j][c]) break;
          if (j>=2) break;
        }
        if (d>=26) break;
      }
    }
    if (c>=26) r.push_back(i-m+2);
    }
  }
  printf("%d\n",int(r.size()));
  for (i=0; i<r.size(); i++) printf("%d%c",r[i],(i+1==r.size())?'\n':' ');
  return 0;
}