#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int i,j,n,m,mx,wi,wj,nx[50005][26],f[50005][52],p[50005][52];
vector<int> a;
char s[50005];
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (j=0; j<26; j++) nx[0][j]=-1;
  for (i=0; i<n; i++) {
    for (j=0; j<26; j++) nx[i+1][j]=nx[i][j];
	nx[i+1][s[i]-'a']=i;
  }
  memset(f,255,sizeof(f));
  f[0][0]=n;
  for (i=0; i<n; i++) for (j=0; j<=50; j++) {
    if (f[i][j]>=i) {
	  if (j+j>mx) {
	    mx=j+j; wi=i; wj=j;
	  }
	  f[i+1][j]=max(f[i+1][j],f[i][j]);
	}
    if (j<50 && f[i][j]>i) {
	  if (j+j+1>mx) {
	    mx=j+j+1; wi=i; wj=j;
	  }
	  f[i+1][j+1]=nx[f[i][j]][s[i]-'a'];
	}
  }
  for (i=wi, j=wj; i>0; i--) {
    if (f[i][j]==n) break;
    if (s[i-1]==s[f[i][j]]) {
	  j--;
	  a.push_back(i-1);
	}
  }
  m=a.size(); m--;
  for (i=m; i>=0; i--) putchar(s[a[i]]);
  if (mx%2==1) putchar(s[wi]);
  for (i=0; i<=m; i++) putchar(s[a[i]]);
  return 0;
}