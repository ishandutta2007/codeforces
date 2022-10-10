#include <stdio.h>
int n,i,m,tot,r,a[14],b[14],c[14],f[14][5];
char s[22];
bool w;
void back(int i, int j, int k) {
  if (f[i][j]==0) return;
  if (j==0) {
    for (int x=k-2; x>=0; x--) {
	  putchar(s[x]);
	  if (x>0 && s[x]=='0' && s[x+1]=='.' && s[x-1]!='.') printf("%d\n",1/0);
	}
	putchar('\n');
    return;
  }
  s[k++]='0'+a[i-1];
  s[k]='.';
  back(i-1,j-1,k+1);
  if (i<=1) return;
  s[k++]='0'+a[i-2];
  s[k]='.';
  int x=a[i-2]*10+a[i-1];
  if (x>=10 && x<=99) back(i-2,j-1,k+1);
  if (i<=2) return;
  s[k++]='0'+a[i-3];
  s[k]='.';
  x=a[i-3]*100+a[i-2]*10+a[i-1];
  if (x>=100 && x<=255) back(i-3,j-1,k+1);
}
void check() {
  f[0][0]=1;
  for (int i=1; i<=m; i++) {
    f[i][0]=0;
    for (int j=1; j<=4; j++) {
	  f[i][j]=f[i-1][j-1];
	  if (i>1) {
	    int x=a[i-2]*10+a[i-1];
	    if (x>=10 && x<=99) f[i][j]+=f[i-2][j-1];
	  }
	  if (i>2) {
	    int x=a[i-3]*100+a[i-2]*10+a[i-1];
	    if (x>=100 && x<=255) f[i][j]+=f[i-3][j-1];
	  }
    }
  }
  if (w) back(m,4,0);
  r+=f[m][4];
}
void rec(int l) {
  if (tot==n) {
    m=2*l-1;
    for (int i=0; i<l; i++) a[m-1-i]=a[i];
	check();
	m=2*l;
	for (int i=0; i<l; i++) a[m-1-i]=a[i];
	check();
  }
  if (l==6) return;
  for (int i=0; i<n; i++) {
    a[l]=b[i];
	if (++c[i]==1) tot++;
	rec(l+1);
	if (--c[i]==0) tot--;
  }
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&b[i]);
  rec(0);
  printf("%d\n",r);
  int sr=r;
  w=true;
  rec(0);
  if (2*sr!=r) printf("%d\n",1/0);
  return 0;
}