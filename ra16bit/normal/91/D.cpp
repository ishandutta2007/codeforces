#include <cstdio>
#include <vector>
using namespace std;
int i,j,k,n,m,r,z,a[100100],ans[100100][5],b[100100][5],d[100100],bb[5];
vector <int> db[5],c[100100];
bool u[200200];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) if (!u[i]) {
    k=0;
    for (j=i; !u[j]; j=a[j], k++) { u[j]=true; c[m].push_back(j); }
    if (k%4<=1) {
      if (k>1) for (int i=0; i<k/4; i++,r++) {
        d[r]=(i==k/4-1 && k%4==0)?4:5;
        ans[r][0]=c[m][0];
        ans[r][1]=c[m][i*4+1];
        ans[r][2]=c[m][i*4+2];
        ans[r][3]=c[m][i*4+3];
        if (d[r]==5) ans[r][4]=c[m][i*4+4];
        b[r][0]=ans[r][1];
        b[r][1]=ans[r][2];
        b[r][2]=ans[r][3];
        if (d[r]==5) b[r][3]=ans[r][4]; else b[r][3]=ans[r][0];
        if (d[r]==5) b[r][4]=ans[r][0];
      }
      c[m].clear();
    } else {
      for (int i=0; i<k/4; i++,r++) {
        d[r]=5;
        ans[r][0]=c[m][0];
        ans[r][1]=c[m][i*4+1];
        ans[r][2]=c[m][i*4+2];
        ans[r][3]=c[m][i*4+3];
        ans[r][4]=c[m][i*4+4];
        b[r][0]=ans[r][1];
        b[r][1]=ans[r][2];
        b[r][2]=ans[r][3];
        b[r][3]=ans[r][4];
        b[r][4]=ans[r][0];
      }
      db[k%4].push_back(m++); bb[k%4]++;
    }
  }
  while (bb[2]>0 && bb[3]>0) {
    d[r]=5;
    int d1=db[2][bb[2]-1],d2=db[3][bb[3]-1];
    ans[r][0]=c[d1][0];
    ans[r][1]=c[d1][c[d1].size()-1];
    ans[r][2]=c[d2][0];
    ans[r][3]=c[d2][c[d2].size()-2];
    ans[r][4]=c[d2][c[d2].size()-1];
    b[r][0]=ans[r][1];
    b[r][1]=ans[r][0];
    b[r][2]=ans[r][3];
    b[r][3]=ans[r][4];
    b[r][4]=ans[r][2];
    bb[2]--; bb[3]--; r++;
  }
  while (bb[2]>1) {
    d[r]=4;
    int d1=db[2][bb[2]-1],d2=db[2][bb[2]-2];
    ans[r][0]=c[d1][0];
    ans[r][1]=c[d1][c[d1].size()-1];
    ans[r][2]=c[d2][0];
    ans[r][3]=c[d2][c[d2].size()-1];
    b[r][0]=ans[r][1];
    b[r][1]=ans[r][0];
    b[r][2]=ans[r][3];
    b[r][3]=ans[r][2];
    bb[2]-=2; r++;
  }
  while (bb[3]>2) {
    d[r]=5;
    int d1=db[3][bb[3]-1],d2=db[3][bb[3]-2];
    ans[r][0]=c[d1][0];
    ans[r][1]=c[d1][c[d1].size()-2];
    ans[r][2]=c[d1][c[d1].size()-1];
    ans[r][3]=c[d2][0];
    ans[r][4]=c[d2][c[d2].size()-2];
    b[r][0]=ans[r][1];
    b[r][1]=ans[r][2];
    b[r][2]=ans[r][0];
    b[r][3]=ans[r][4];
    b[r][4]=ans[r][3];
    bb[3]--; d[++r]=5;
    d2=db[3][bb[3]-1],d1=db[3][bb[3]-2];
    ans[r][0]=c[d1][0];
    ans[r][1]=c[d1][c[d1].size()-2];
    ans[r][2]=c[d1][c[d1].size()-1];
    ans[r][3]=c[d2][0];
    ans[r][4]=c[d2][c[d2].size()-1];
    b[r][0]=ans[r][1];
    b[r][1]=ans[r][2];
    b[r][2]=ans[r][0];
    b[r][3]=ans[r][4];
    b[r][4]=ans[r][3];
    bb[3]-=2; r++;
  }
  while (bb[3]>0) {
    d[r]=3;
    int d1=db[3][bb[3]-1];
    ans[r][0]=c[d1][0];
    ans[r][1]=c[d1][c[d1].size()-2];
    ans[r][2]=c[d1][c[d1].size()-1];
    b[r][0]=ans[r][1];
    b[r][1]=ans[r][2];
    b[r][2]=ans[r][0];
    bb[3]--; r++;
  }
  if (bb[2]>0) {
    d[r]=2;
    int d1=db[2][bb[2]-1];
    ans[r][0]=c[d1][0];
    ans[r][1]=c[d1][c[d1].size()-1];
    b[r][0]=ans[r][1];
    b[r][1]=ans[r][0];
    bb[2]--; r++;
  }
  printf("%d\n",r);
  for (i=0; i<r; i++) {
    printf("%d\n",d[i]);
    for (j=0; j<d[i]; j++) {
      if (j) putchar(' ');
      printf("%d",ans[i][j]);
    }
    puts("");
    for (j=0; j<d[i]; j++) {
      if (j) putchar(' ');
      printf("%d",b[i][j]);
    }
    puts("");
  }
  return 0;
}