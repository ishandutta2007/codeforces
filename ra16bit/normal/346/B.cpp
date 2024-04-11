#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,z,i,j,k,e,w,l,p[102],c[102][28],f[102][102][102];
char a[102],b[102],s[102],r[102];
int main() {
  scanf("%s",a); n=strlen(a);
  scanf("%s",b); m=strlen(b);
  scanf("%s",s); z=strlen(s);
  for (i=0; i<z; i++) {
    for (j=i-1; j>=0; j--) {
	  for (k=j; k>=0; k--) if (s[k]!=s[i-j+k]) break;
	  if (k<0) break;
	}
	p[i]=j+1;
  }
  for (i=0; i<z; i++) for (j='A'; j<='Z'; j++) {
    for (k=i; k>0; k=p[k-1]) if (s[k]==j) break;
	if (s[k]==j) k++;
	c[i][j-'A']=k;
  }
  for (i=0; i<=n; i++) for (j=0; j<=m; j++) for (k=0; k<z; k++) if (k<=f[i][j][k]) {
    if (i<n) {
	  f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]);
	  if (j<m && a[i]==b[j]) {
	    e=c[k][a[i]-'A'];
	    if (e<z) f[i+1][j+1][e]=max(f[i+1][j+1][e],f[i][j][k]+1);
	  }
	}
	if (j<m) f[i][j+1][k]=max(f[i][j+1][k],f[i][j][k]);
  }
  for (e=k=0; k<z; k++) if (k<=f[n][m][k] && f[n][m][k]>e) {
    e=f[n][m][k]; w=k;
  }
  if (e>0) {
    for (i=n, j=m, k=w, e--; i>0 && j>0; ) {
      if (a[i-1]==b[j-1]) {
	    for (l=0; l<z; l++) if (l<=f[i-1][j-1][l] && c[l][a[i-1]-'A']==k && f[i][j][k]==f[i-1][j-1][l]+1) break;
		if (l<z) {
	      r[e--]=a[i-1];
	      k=l; i--; j--;
	      continue;
		}
	  }
	  if (f[i-1][j][k]==f[i][j][k]) i--; else j--;
    }
	puts(r);
  } else puts("0");
  return 0;
}