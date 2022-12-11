#include<bits/stdc++.h> 
using namespace std;
const int Dx[]={0,1,0,-1},Dy[]={1,0,-1,0};
int n,m,Sx,Sy,use[10],a[10],ans,i,j,l;
char s1[1010],s[110][110];
int getans(){
	//printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
	int x=Sx,y=Sy;
	for(int i=1;i<=l;i++){
		x+=Dx[a[s1[i]-'0']];
		y+=Dy[a[s1[i]-'0']];
		if(s[x][y]=='E')return 1;
		if(s[x][y]!='.')return 0;
	}
	return 0;
}
void dfs(int x){
	if(x>4)ans+=getans();
	for(int i=0;i<4;i++)
		if(!use[i])use[i]=1,a[x-1]=i,dfs(x+1),use[i]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(j=1;j<=m;j++)
			if(s[i][j]=='S')Sx=i,Sy=j,s[i][j]='.';
	}
	scanf("%s",s1+1);
	l=strlen(s1+1);
	dfs(1);
	printf("%d\n",ans);
}