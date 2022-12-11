#include<bits/stdc++.h>
using namespace std;
int ans,flag,a[20][300010],n,i,x,anx[20],as[20];
void dfs(int x,int y){
	if(y>=ans)return;
	//printf("%d %d\n",x,y);
	if(x<2){
		anx[1]=0;
		if(a[x][0]){
			y++;
			anx[1]=-1;
		}
		if(a[x][2]){
			y++;
			anx[1]=1;
		}
		if(y<ans){
			ans=y;
			for(int i=1;i<=18;i++)
				as[i]=anx[i];
		}
		return;
	}
	int flag=0;
	for(int i=0;i<=1<<x-1;i++)
		a[x-1][i]=0; 
	for(int i=0;i<=1<<x;i++)
	if(a[x][i]){
		//printf("%d ",i); 
		if(i&1)flag=1;
		a[x-1][i>>1]=1;
	}
	//puts("");
	anx[x]=flag;
	dfs(x-1,y+flag);
	if(flag){
		for(int i=0;i<=1<<x-1;i++)
			a[x-1][i]=0;
		for(int i=0;i<=1<<x;i++)
			if(a[x][i])a[x-1][i+1>>1]=1;
		anx[x]=-flag;
		dfs(x-1,y+flag);
	}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&x),a[18][x+(1<<17)]=1;
	ans=20;
	dfs(18,0);
	printf("%d\n",ans);
	for(i=18;i>=1;i--)
		if(as[i])printf("%d ",as[i]*(1<<18-i));
}