#include <bits/stdc++.h>
using namespace std;
const int md=1000000007;
int n,m,i,j,cnt,r,f[1010][1010];
char s[55][1010];
long long a[1010];
bool u[1010];
int main() {
  scanf("%d%d",&m,&n);
  for (i=0; i<n; i++) {
    scanf("%s",s[i]);
	for (j=0; j<m; j++) a[j]=a[j]*2+s[i][j]-'0';
  }
  f[0][0]=1;
  for (i=0; i<m; i++) for (j=0; j<=i; j++) if (f[i][j]) {
    f[i+1][j]=(f[i+1][j]+1LL*f[i][j]*j)%md;
	f[i+1][j+1]=(f[i+1][j+1]+f[i][j])%md;
  }
  for (i=0; i<=m; i++) for (j=1; j<=i; j++) f[i][j]=(f[i][j]+f[i][j-1])%md;
  for (r=1, i=0; i<m; i++) if (!u[i]) {
    cnt=1;
    for (j=i+1; j<m; j++) if (a[i]==a[j]) { u[j]=true; cnt++; }
	r=(1LL*r*f[cnt][cnt])%md;
  }
  printf("%d\n",r);
  return 0;
}