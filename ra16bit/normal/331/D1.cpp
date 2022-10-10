#include <stdio.h>
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const char dz[4]={'R','U','L','D'};
int n,m,bs,i,j,xa,ya,xb,yb,xx,yy,dd,d[1010],a[1010][1010],g[1010],c[1010],x[1010],y[1010],u[1010],f[1010],it;
long long cnt,cur;
char s[5];
int main() {
  scanf("%d%d",&n,&bs);
  for (i=1; i<=n; i++) {
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
	x[i]=xb; y[i]=yb;
	if (xa==xb) {
	  if (ya>yb) {
	    d[i]=3;
		for (j=yb; j<=ya; j++) a[xa][j]=i;
	  } else {
	    d[i]=1;
		for (j=ya; j<=yb; j++) a[xa][j]=i;
	  }
	} else {
	  if (xa>xb) {
	    d[i]=2;
		for (j=xb; j<=xa; j++) a[j][ya]=i;
	  } else {
	    d[i]=0;
		for (j=xa; j<=xb; j++) a[j][ya]=i;
	  }
	}
  }
  for (i=1; i<=n; i++) {
    for (xx=x[i], yy=y[i], dd=d[i]; xx>=0 && yy>=0 && xx<=bs && yy<=bs; xx+=dx[dd], yy+=dy[dd], c[i]++) {
	//printf("%d %d %d\n",xx,yy,dd);
	  j=a[xx][yy];
	  if (j>0) {
	    dd=d[j];
		//printf("%d\n",j);
	    if (c[i]>0 && x[j]==xx && y[j]==yy) break;
      }
    }
	if (xx>=0 && yy>=0 && xx<=bs && yy<=bs) g[i]=j;
	//printf("%d : %d %d\n",i,g[i],c[i]);
  }
  scanf("%d",&m);
  while (m--) {
    scanf("%d%d",&xx,&yy);
	scanf("%s",s);
	for (dd=0; dd<4; dd++) if (dz[dd]==s[0]) break;
	scanf("%I64d",&cnt);
    for (; xx>=0 && yy>=0 && xx<=bs && yy<=bs; xx+=dx[dd], yy+=dy[dd], cnt--) {
	  if (cnt==0) break;
	  j=a[xx][yy];
	  if (j>0) {
	    dd=d[j];
	    if (x[j]==xx && y[j]==yy) break;
      }
    }
	if (xx>=0 && yy>=0 && xx<=bs && yy<=bs) {
	  if (cnt==0) {
	    printf("%d %d\n",xx,yy);
	    continue;
	  }  
	} else {
	  printf("%d %d\n",xx-dx[dd],yy-dy[dd]);
	  continue;
	}
	for (cur=0, ++it; ; j=g[j]) {
	  if (u[j]==it) {
	    //puts("!");
		//printf("%I64d %d %I64d\n",cur,f[j],cnt);
	    cnt-=f[j];
		cnt%=cur-f[j];
		cur=0;
		++it;
	  }
	  xx=x[j]; yy=y[j]; dd=d[j];
	  //printf("%d | %I64d %I64d\n",j,cur,cnt);
	  if (g[j]==0 || cur+c[j]>cnt) {
	    cnt-=cur;
	    break;
	  }
	  u[j]=it; f[j]=cur; cur+=c[j];
	}
	//printf("%I64d\n",cnt);
    for (; xx>=0 && yy>=0 && xx<=bs && yy<=bs; xx+=dx[dd], yy+=dy[dd], cnt--) {
	  if (cnt==0) break;
	  j=a[xx][yy];
	  if (j>0) dd=d[j];
    }
	if (xx>=0 && yy>=0 && xx<=bs && yy<=bs) printf("%d %d\n",xx,yy); else printf("%d %d\n",xx-dx[dd],yy-dy[dd]);
  }
  return 0;
}