#include<algorithm>
#include<queue>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxm=1e4+5,maxg=1e3+5;
int n,m,d[maxm],g,r;
int dis[maxm][maxg];
bool vis[maxm][maxg];
typedef pair<int,int> pii;
void bfs(){
	deque<pii> dq;
	dq.push_back(pii(0,0));
	dis[0][0]=0;
	vis[0][0]=1;
	while(!dq.empty()){
		pii u=dq.front();
		dq.pop_front();
		if(u.first>0){
			if(u.second+d[u.first]-d[u.first-1]<g){
				if(!vis[u.first-1][u.second+d[u.first]-d[u.first-1]]){
					dis[u.first-1][u.second+d[u.first]-d[u.first-1]]=dis[u.first][u.second];
					vis[u.first-1][u.second+d[u.first]-d[u.first-1]]=1;
					dq.push_front(pii(u.first-1,u.second+d[u.first]-d[u.first-1]));
				}
			}
			else if(u.second+d[u.first]-d[u.first-1]==g){
				if(!vis[u.first-1][0]){
					dis[u.first-1][0]=dis[u.first][u.second]+1;
					vis[u.first-1][0]=1;
					dq.push_back(pii(u.first-1,0));
				}
			}
		}
		if(u.first<m-2){
			if(u.second+d[u.first+1]-d[u.first]<g){
				if(!vis[u.first+1][u.second+d[u.first+1]-d[u.first]]){
					dis[u.first+1][u.second+d[u.first+1]-d[u.first]]=dis[u.first][u.second];
					vis[u.first+1][u.second+d[u.first+1]-d[u.first]]=1;
					dq.push_front(pii(u.first+1,u.second+d[u.first+1]-d[u.first]));
				}
			}
			else if(u.second+d[u.first+1]-d[u.first]==g){
				if(!vis[u.first+1][0]){
					dis[u.first+1][0]=dis[u.first][u.second]+1;
					vis[u.first+1][0]=1;
					dq.push_back(pii(u.first+1,0));
				}
			}
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=0;i<m;i++) d[i]=readint();
	sort(d,d+m);
	g=readint();
	r=readint();
	bfs();
	int ans=2e9;
	for(int i=0;i<m-1;i++) if(vis[i][0]&&d[m-1]-d[i]<=g)
		ans=min(ans,dis[i][0]*(r+g)+d[m-1]-d[i]);
	if(ans<2e9) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}