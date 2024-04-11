#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int n,m,i,sum,last,a[19],b[7][7],c[7],gd,pd;
map <int, int> M;
bool q;
void rec(int x, int y, int cur) {
  //printf("here is %d %d (%d)\n",x,y,cur);
  //for (int i=1; i<=n; i++) printf("%d ",c[i]); puts(",<- vsums");
  //for (int i=0; i<m; i++) printf("%d : %d\n",a[i],M[a[i]]);
  //for (int i=1; i<=n; i++) for (int j=1; j<=n; j++)  printf("%d%c",b[i][j],j==n?'\n':' ');
  //puts("----");
  if (y==last) {
    //puts("~~");
      for (int i=0; i<m; i++) if (M[a[i]]>0) {
        b[x][y]=a[i];
        c[y]+=a[i];
        if (x==y) gd+=a[i];
        if (x==n-y+1) pd+=a[i];
        int z=sum-cur-a[i];
        M[a[i]]--;
        if (M.count(z)>0 && M[z]>0) {
          //puts("ok1");
            M[z]--;
            b[x][y+1]=z;
            if (x==y+1) gd+=z;
            if (x==n-y) pd+=z;
            c[y+1]+=z;
            if (x==last) {
            //puts("ok2");
              int e=sum-c[y+1],f=sum-c[y];
              if (M.count(e)>0 && M[e]>0) {
                  //puts("ok3");
                  b[x+1][y+1]=e;
                  gd+=e;
                  M[e]--;
                  if (gd==sum && M.count(f)>0 && M[f]>0) {
                  //puts("ok4");
                      b[x+1][y]=f;
                      if (y==1) pd+=f;
                      if (pd==sum) {
                        q=true;
                        for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) printf("%d%c",b[i][j],j==n?'\n':' ');
                        return;
                      }
                      if (y==1) pd-=f;
                  }
                  gd-=e;
                  M[e]++;
              }
            } else rec(x+1,1,0);
            c[y+1]-=z;
            if (x==y+1) gd-=z;
            if (x==n-y) pd-=z;
            M[z]++;
        }
        M[a[i]]++;
        c[y]-=a[i];
        if (x==y) gd-=a[i];
        if (x==n-y+1) pd-=a[i];
        if (q) return;
      }
      return;
  }
  for (int i=0; i<m; i++) if (M[a[i]]>0) {
    b[x][y]=a[i];
    c[y]+=a[i];
    if (x==y) gd+=a[i];
    if (x==n-y+1) pd+=a[i];
    if (x==last) {
      //puts("!");
      int z=sum-c[y];
      if (y==1) pd+=z;
      M[a[i]]--;
      if (M.count(z)>0 && M[z]>0) {
        M[z]--;
        b[x+1][y]=z;
        rec(x,y+1,cur+a[i]);
        M[z]++;
      }
      if (y==1) pd-=z;
      M[a[i]]++;
    } else {
      M[a[i]]--;
      rec(x,y+1,cur+a[i]);
      M[a[i]]++;
    }
    c[y]-=a[i];
    if (x==y) gd-=a[i];
    if (x==n-y+1) pd-=a[i];
    if (q) return;
  }
}
int main() {
  scanf("%d",&n);
  m=n*n; last=n-1;
  for (i=0; i<m; i++) {
    scanf("%d",&a[i]);
    sum+=a[i];
    M[a[i]]++;
  }
  sort(a,a+m);
  m=unique(a,a+m)-a;
  sum/=n;
  if (n==1) {
    printf("%d\n%d\n",sum,a[0]);
    return 0;
  }
  printf("%d\n",sum);
  rec(1,1,0);
  return 0;
}