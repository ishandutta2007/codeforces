#include <cstdio>
using namespace std;
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};
int t,m,n,i,j,r,k,k1,k2,k3,k4,z,a[255][255];
bool u[255][255],q;
char s[255][255];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m); gets(s[0]); r=0;
    for (i=0; i<=m+1; i++) s[0][i]=s[n+1][i]='0';
    for (i=1; i<=n; i++) {
      gets(s[i]+1); s[i][0]=s[i][m+1]='0';
    }
    for (i=1; i<=n; i++) for (j=1; j<=m; j++) {
      u[i][j]=false; a[i][j]=0;
      for (k=0; k<8; k++) a[i][j]+=(s[i+dx[k]][j+dy[k]]-'0');
    }
    for (i=1; i<=n; i++) for (j=1; j<=m; j++) if (s[i][j]=='1' && !u[i][j]) {
      if (s[i+1][j]=='1') {
        if (i<n && j<m && s[i+2][j]=='1' && s[i+2][j+1]=='1' && s[i+2][j+2]=='1' && s[i+1][j+2]=='1' && s[i][j+1]=='1' && s[i][j+2]=='1') {
          if (a[i][j]==2 && a[i+2][j]==2 && a[i+2][j+2]==2 && a[i][j+2]==2 && a[i][j+1]==4 && a[i+1][j]==4 && a[i+1][j+2]==4 && a[i+2][j+1]==4) r++;
          continue;
        }
        q=true;
        for (z=k1=0; s[i+k1][j]=='1'; k1++) {
          u[i+k1][j]=true;
          if (a[i+k1][j]!=2) { 
            if (a[i+k1][j]==3) z++; else {
              q=false; break;
            }
          }
        }
        if (z!=2) q=false;
        if (q) for (z=k2=0; s[i+k1-1][j+k2]=='1'; k2++) {
          u[i+k1-1][j+k2]=true;
          if (a[i+k1-1][j+k2]!=2) {
            if (a[i+k1-1][j+k2]==3) z++; else {
              q=false; break;
            }
          }
        }
        if (z!=2) q=false;
        if (q) for (z=k3=0; s[i+k1-1-k3][j+k2-1]=='1'; k3++) {
          u[i+k1-1-k3][j+k2-1]=true;
          if (a[i+k1-1-k3][j+k2-1]!=2) {
            if (a[i+k1-1-k3][j+k2-1]==3) z++; else {
              q=false; break;
            }
          }
        }
        if (z!=2) q=false;
        if (q) for (z=k4=0; s[i+k1-k3][j+k2-1-k4]=='1'; k4++) {
          u[i+k1-k3][j+k2-1-k4]=true;
          if (a[i+k1-k3][j+k2-1-k4]!=2) {
            if (a[i+k1-k3][j+k2-1-k4]==3) z++; else {
              q=false; break;
            }
          }
        }
        if (z!=2) q=false;
        if (q && k1==k2 && k2==k3 && k3==k4) r++;
      } else if (s[i+1][j-1]=='1') {
        q=true;
        for (k1=0; s[i+k1][j-k1]=='1'; k1++) {
          u[i+k1][j-k1]=true;
          if (a[i+k1][j-k1]!=2) { q=false; break; }
        }
		k1--;
        if (q) for (k2=0; s[i+k1+k2][j-k1+k2]=='1'; k2++) {
          u[i+k1+k2][j-k1+k2]=true;
          if (a[i+k1+k2][j-k1+k2]!=2) { q=false; break; }
        }
		k2--;
        if (q) for (k3=0; s[i+k1+k2-k3][j-k1+k2+k3]=='1'; k3++) {
          u[i+k1+k2-k3][j-k1+k2+k3]=true;
          if (a[i+k1+k2-k3][j-k1+k2+k3]!=2) { q=false; break; }
        }
		k3--;
        if (q) for (k4=0; s[i+k1+k2-k3-k4][j-k1+k2+k3-k4]=='1'; k4++) {
          u[i+k1+k2-k3-k4][j-k1+k2+k3-k4]=true;
          if (a[i+k1+k2-k3-k4][j-k1+k2+k3-k4]!=2) { q=false; break; }
        }
		k4--;
        if (q && k1==k2 && k2==k3 && k3==k4) r++;
      }
    }
    printf("%d\n",r);
  }
  return 0;
}