#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define pb push_back
using namespace std;
const int N=1e2+9;
char s[N][N],ans[N][N];
int r,c,k,tot,num;
void dfs(int x,int y,bool pos,int sum,int id){
	if(x==r)return;
	ans[x][y]=id;
	if(s[x][y]=='R')++sum;
	if(id+tot<k){
		if(sum==num)sum=0,id++;
	}
	else{
		if(sum==num+1)sum=0,id++;
	}
	if(y==0&&!pos){
		dfs(x+1,y,1,sum,id);
		return;
	}
	if(y==c-1&&pos){
		dfs(x+1,y,0,sum,id);
		return;
	}
	if(pos)dfs(x,y+1,1,sum,id);
	else dfs(x,y-1,0,sum,id);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&r,&c,&k);
		rep(i,0,r)scanf("%s",s+i);
		tot=0;
		rep(i,0,r)rep(j,0,c)if(s[i][j]=='R')++tot;
		num=tot/k;
		tot-=num*k;
		dfs(0,0,1,0,0);
		rep(i,0,r){
			rep(j,0,c){
				if(ans[i][j]>=k)ans[i][j]=k-1;
				if(ans[i][j]<10)ans[i][j]+=48;
				else if(ans[i][j]<36)ans[i][j]+='a'-10;
				else if(ans[i][j]<62)ans[i][j]+='A'-36;
			}
			ans[i][c]=0;
			printf("%s\n",ans[i]);
		}
	}
}