#include <bits/stdc++.h>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int an,n,m,i,j,sx,sy,r,d[4];
char s[55][55],a[111];
bool u[4];
void rec(int l) {
  if (l==4) {
    int x=sx,y=sy,i=0;
	bool ok=false;
    for (; i<an; i++) {
	  int cur=d[a[i]-'0'];
	  x+=dx[cur];
	  y+=dy[cur];
	  if (x<0 || y<0 || x>=n || y>=m || s[x][y]=='#') break;
	  if (s[x][y]=='E') { ok=true; break; }
	}
	if (ok) r++;
    return;
  }
  for (int i=0; i<4; i++) if (!u[i]) {
    d[l]=i;
	u[i]=true;
	rec(l+1);
	u[i]=false;
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%s",s[i]);
	for (j=0; j<m; j++) if (s[i][j]=='S') { sx=i; sy=j; }
  }
  scanf("%s",a);
  an=strlen(a);
  rec(0);
  printf("%d\n",r);
  return 0;
}