#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct DATA_T{
  int x,y,d,w;
};
bool operator<(DATA_T a,DATA_T b){
  return a.w>b.w;
}


char f[1024][1024];
bool c[1024],r[1024];
int n,m;

int dx[]={1,0,-1,0},dy[]={0,1,0,-1};


int main(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++)
    scanf("%s",f[i]);

  priority_queue<DATA_T>Q;
  Q.push((DATA_T){-1,0,0,0});
  int ans=-1;
  for(;ans==-1 && !Q.empty();){
    DATA_T e=Q.top();Q.pop();
    for(;;){
      e.x+=dx[e.d];
      e.y+=dy[e.d];
      if(e.x==m && e.y==n-1){ans=e.w;break;}
      if(e.x==m || e.x<0 || e.y==n || e.y<0)break;
      if(f[e.y][e.x]=='#'){
	f[e.y][e.x]='.';
	if(dy[e.d]==0){
	  if(c[e.x])continue;
	  c[e.x]=1;
	}else{
	  if(r[e.y])continue;
	  r[e.y]=1;
	}

	Q.push((DATA_T){e.x,e.y,(e.d+1)%4,e.w+1});
	Q.push((DATA_T){e.x,e.y,(e.d+3)%4,e.w+1});
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}