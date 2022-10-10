#include <cstdio>
#include <algorithm>
using namespace std;
const int inf=100000000;
int n,m,i,j,cur,cnt,x,y,ll=inf,rr,uu=inf,res=inf,dd,le[1010],ri[1010],up[1010],dw[1010],a[1010][1010];
char s[1010][1010];
bool solve(int x, int y) {
  int i=ll+x,j=uu+y,need=x*y;
  int cur=a[i][j]-a[i-x][j]-a[i][j-y]+a[i-x][j-y];
  if (cur!=need) return false;
  while (true) {
    int now=a[i+1][j]-a[i+1-x][j]-a[i+1][j-y]+a[i+1-x][j-y];
    if (now==need) {
      cur+=y; i++;
    } else {
      now=a[i][j+1]-a[i-x][j+1]-a[i][j+1-y]+a[i-x][j+1-y];
      if (now==need) {
        cur+=x; j++;
      } else break;
    }
  }
  return (cur==cnt);
}
int main() {
  scanf("%d%d",&n,&m);
  for (j=0; j<m; j++) up[j]=inf;
  for (i=0; i<n; i++) {
    scanf("%s",s[i]);
    le[i]=inf;
    for (j=0; j<m; j++) {
      a[i+1][j+1]=a[i][j+1]+a[i+1][j]-a[i][j]+int(s[i][j]=='X');
      if (s[i][j]=='X') {
        ll=min(ll,i); rr=i;
        uu=min(uu,j); dd=j;
        le[i]=min(le[i],j); ri[i]=j;
        up[j]=min(up[j],i); dw[j]=i;
        cnt++;
      }
    }
  }
  cur=a[rr+1][dd+1]-a[rr+1][uu]-a[ll][dd+1]+a[ll][uu];
  if (cur==cnt && cur==(rr-ll+1)*(dd-uu+1)) {
    printf("%d\n",min(rr-ll+1,dd-uu+1));
    return 0;
  }
  for (i=ll+1; i<=rr; i++) if (le[i]!=le[ll]) break;
  if (i<=rr && le[i]<=ri[ll]) {
    x=i-ll;
    y=ri[ll]-le[i]+1;
    if (solve(x,y)) res=x*y;
  }
  for (i=uu+1; i<=dd; i++) if (up[i]!=up[uu]) break;
  if (i<=dd && up[i]<=dw[uu]) {
    x=dw[uu]-up[i]+1;
    y=i-uu;
    if (solve(x,y)) res=min(res,x*y);
  }
  if (res<inf) printf("%d\n",res); else puts("-1");
  return 0;
}