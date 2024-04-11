#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,x,nx[100100][28],c[3],d[3],dep[3],p[3][1010],f[252][252][252];
char s[100100],st[3][252],e[5];
int main() {
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  for (j=0; j<26; j++) nx[n+1][j]=n;
  for (i=n; i>=0; i--) {
    for (j=0; j<26; j++) nx[i][j]=nx[i+1][j];
	if (i<n) nx[i][s[i]-'a']=i;
  }
  while (m--) {
    scanf("%s",e);
	bool v=(e[0]=='+');
	scanf("%d",&x);
	x--;
	if (v) {
	  scanf("%s",e);
	  st[x][++dep[x]]=e[0];
	  p[x][c[x]]=d[x];
	  d[x]=c[x];
	  for (i=0; i<=dep[0]; i++) if (x!=0 || i==dep[0])
	    for (j=0; j<=dep[1]; j++) if (x!=1 || j==dep[1])
		  for (k=0; k<=dep[2]; k++) if (x!=2 || k==dep[2]) {
		    f[i][j][k]=((i==0 && j==0 && k==0)?0:(n+1));
			if (i>0) f[i][j][k]=min(f[i][j][k],nx[f[i-1][j][k]][st[0][i]-'a']+1);
			if (j>0) f[i][j][k]=min(f[i][j][k],nx[f[i][j-1][k]][st[1][j]-'a']+1);
			if (k>0) f[i][j][k]=min(f[i][j][k],nx[f[i][j][k-1]][st[2][k]-'a']+1);
		  }
	} else {
	  d[x]=p[x][d[x]];
	  dep[x]--;
	}
	puts((f[dep[0]][dep[1]][dep[2]]<=n)?"YES":"NO");
  }
  return 0;
}