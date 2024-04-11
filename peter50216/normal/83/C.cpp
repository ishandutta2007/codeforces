#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n,m,k;
char in[55][55];
int used[300];
char ap[100],apc;
//bool cang[300];
string ans;
int sx,sy;
int ex,ey;
int all[300],ac;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int que[3000][2];
int vis[55][55];
int dis[55][55];
int visid;
vector<pair<int,int> > pos[2000];
inline void solve(){
    int i,j;
    //for(i=0;i<ac;i++)printf("%c",all[i]);puts("");
    visid++;
    int qs=0,qe=0;
    que[qe][0]=sx;que[qe][1]=sy;qe++;
    vis[sx][sy]=visid;
    dis[sx][sy]=0;
    while(qs<qe){
	int x=que[qs][0],y=que[qs][1];
	//printf("%d %d\n",x,y);
	qs++;
	for(i=0;i<ac;i++){
	    for(j=0;j<4;j++){
		int xx=x+dx[j],yy=y+dy[j];
		if(xx>=0&&xx<n&&yy>=0&&yy<m&&vis[xx][yy]!=visid&&in[xx][yy]==all[i]){
		    que[qe][0]=xx;que[qe][1]=yy;qe++;
		    vis[xx][yy]=visid;
		    dis[xx][yy]=dis[x][y]+1;
		}
	    }
	}
	for(j=0;j<4;j++){
	    int xx=x+dx[j],yy=y+dy[j];
	    if(xx>=0&&xx<n&&yy>=0&&yy<m&&vis[xx][yy]!=visid&&in[xx][yy]=='S'){
		que[qe][0]=xx;que[qe][1]=yy;qe++;
		vis[xx][yy]=visid;
		dis[xx][yy]=dis[x][y]+1;
	    }
	}
    }
    if(vis[ex][ey]!=visid)return;
    string str;
    int d=dis[ex][ey];
    pos[d].clear();
    pos[d].push_back(make_pair(ex,ey));
    visid++;
    vis[ex][ey]=visid;
    while(d>1){
	char c='z'+1;
	for(i=0;i<pos[d].size();i++){
	    int x=pos[d][i].first,y=pos[d][i].second;
	    for(j=0;j<4;j++){
		int xx=x+dx[j],yy=y+dy[j];
		if(xx>=0&&xx<n&&yy>=0&&yy<m&&vis[xx][yy]==visid-1&&dis[xx][yy]==dis[x][y]-1){
		    vis[xx][yy]=visid;
		    if(in[xx][yy]<c){
			c=in[xx][yy];
			pos[d-1].clear();
		    }
		    if(in[xx][yy]==c){
			pos[d-1].push_back(make_pair(xx,yy));
		    }
		}
	    }
	}
	str+=c;d--;
    }
    if(str.size()<ans.size()||(str.size()==ans.size()&&str<ans))ans=str;
}
inline void dfs(int np,int c){
    //for(int i=0;i<ac;i++)printf("%d ",all[i]);puts("");
    solve();
    if(np==apc)return;
    dfs(np+1,c);
    if(c<k){
	//	cang[ap[np]]=1;
	all[ac++]=ap[np];
	dfs(np+1,c+1);
	ac--;
	//	cang[ap[np]]=0;
    }
}
int main(){
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)scanf("%s",in[i]);
    for(i=0;i<n;i++)for(j=0;j<m;j++){
	if(in[i][j]=='S')ex=i,ey=j;
	if(in[i][j]=='T')sx=i,sy=j;
	used[in[i][j]]=1;
    }
    for(i='a';i<='z';i++)if(used[i])ap[apc++]=i;
    for(int i=0;i<1000;i++)ans+='z';
    dfs(0,0);
    if(ans.size()==1000)puts("-1");
    else puts(ans.c_str());
}