#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define vi vector<int> 
#define pb push_back
using namespace std;
const int N=5e3+9;
int dis[128][2];
int p[N][2];
char s[N];
int main(){
	dis['L'][0]=-1;
	dis['R'][0]=1;
	dis['D'][1]=-1;
	dis['U'][1]=1;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		rep(i,1,n+1){
			rep(j,0,2)p[i][j]=p[i-1][j]+dis[s[i]][j];
		}
		int ok=0,x=0,y=0;
		per(i,1,n+1){
			int pos[2]={p[i][0],p[i][1]};
			x=0,y=0;
			rep(k,1,n+1){
				int nx=x+dis[s[k]][0],ny=y+dis[s[k]][1];
				if(nx==pos[0]&&ny==pos[1])continue;
				x=nx,y=ny;
			}
			if(!x&&!y){
				ok=1;
				x=pos[0],y=pos[1];
				break;
			}
		}
		if(!ok)puts("0 0");
		else printf("%d %d\n",x,y);
	} 
}