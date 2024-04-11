#include <stdio.h>
int n,m,i,j,k,l,x,y,jj,it,wt,w[111][5],was[555],f[111][22];
int solve(int n) {
  int x=0;
  for (int i=1; i<=n; i++) if (w[i][1]!=it || w[i][2]!=it) {
    int mask=0,e=0,j;
	if (w[i][1]==it) mask|=1;
	if (w[i][2]==it) mask|=2;
    for (j=i+1; j<=n && w[j][1]!=it && w[j][2]!=it; j++,e++);
	if (w[j][1]==it) mask|=4;
	if (w[j][2]==it) mask|=8;
	x^=f[e][mask];
	i=j;
  }
  return x;
}
int main() {
  for (i=0; i<=100; i++) for (j=15; j>=0; j--) {
    wt++;
    for (k=1; k<=i+2; k++) for (l=1; l<=2; l++) {
	  it++;
	  w[0][1]=it; w[i+3][1]=it;
	  w[0][2]=it; w[i+3][2]=it;
	  if (j&1) w[1][1]=it;
	  if (j&2) w[1][2]=it;
	  if (j&4) w[i+2][1]=it;
	  if (j&8) w[i+2][2]=it;
	  if (w[k][l]==it) continue;
	  w[k][l]=it;
	  for (jj=-1; jj<=1; jj++) w[k+jj][3-l]=it;
	  was[solve(i+2)]=wt;
	}
	for (; was[f[i][j]]==wt; f[i][j]++);
  }
  it++;
  scanf("%d%d",&n,&m);
  w[0][1]=it; w[n+1][1]=it;
  w[0][2]=it; w[n+1][2]=it;
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
	w[x][y]=it;
	for (j=-1; j<=1; j++) w[x+j][3-y]=it;
  }
  puts((solve(n)==0)?"LOSE":"WIN");
  return 0;
}