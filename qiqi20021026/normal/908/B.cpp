#include<bits/stdc++.h>

using namespace std;

#define N 120

const int dic[4][2]={-1,0,0,-1,1,0,0,1};
int n,m,sx,sy,ex,ey,x,y,ans,d[4];
char s[N][N],a[N];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (s[i][j]=='S') sx=i,sy=j;
			if (s[i][j]=='E') ex=i,ey=j;
		}
	scanf("%s",a+1); int len=strlen(a+1);
	for (d[0]=0;d[0]<4;d[0]++)
		for (d[1]=0;d[1]<4;d[1]++)
			for (d[2]=0;d[2]<4;d[2]++)
				for (d[3]=0;d[3]<4;d[3]++)
					if (d[0]!=d[1] && d[0]!=d[2] && d[0]!=d[3] && d[1]!=d[2] && d[1]!=d[3] && d[2]!=d[3]){
						x=sx,y=sy;
						for (int i=1;i<=len;i++){
							x=x+dic[d[a[i]-'0']][0],y=y+dic[d[a[i]-'0']][1];
							if (x<=0 || x>n || y<=0 || y>m || s[x][y]=='#') break;
							if (x==ex && y==ey){ans++; break;}
						}
					}
	printf("%d\n",ans);
	
	return 0;
}