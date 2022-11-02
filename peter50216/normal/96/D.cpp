#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define INF 10000000000000000ll
using namespace std;
struct XD{
    int y;
    long long l;
    XD(int yy=0,long long ll=0):y(yy),l(ll){}
};
vector<XD> ed[1010];
int maxd[1010];
int co[1010];
long long dis[1010];
int que[1010],qs,qe;
bool inq[1010];
bool canr[1010][1010];
inline int pop(){
    int a=que[qs++];
    if(qs==1010)qs=0;
    inq[a]=0;
    return a;
}
inline void push(int a){
    if(inq[a])return;
    inq[a]=1;
    que[qe++]=a;
    if(qe==1010)qe=0;
}
int n;
inline void spfa(int st){
    qs=qe=0;
    memset(inq,0,sizeof(inq));
    int i,j;
    for(i=1;i<=n;i++)dis[i]=INF;
    push(st);
    dis[st]=0;
    while(qs!=qe){
	int np=pop();
	for(i=0;i<ed[np].size();i++){
	    int y=ed[np][i].y;
	    long long l=ed[np][i].l+dis[np];
	    if(dis[y]>l){
		dis[y]=l;
		push(y);
	    }
	}
    }
}
bool vis[1010];
int main(){
    int m;
    scanf("%d%d",&n,&m);
    int s,e;
    scanf("%d%d",&s,&e);
    if(s==e){
	puts("0");
	return 0;
    }
    int i,j,k;
    while(m--){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	ed[a].push_back(XD(b,c));
	ed[b].push_back(XD(a,c));
    }
    memset(canr,0,sizeof(canr));
    for(i=1;i<=n;i++){
	scanf("%d%d",&maxd[i],&co[i]);
	spfa(i);
	for(j=1;j<=n;j++)if(dis[j]<=maxd[i]){
	    canr[i][j]=1;
	}
    }
    for(i=1;i<=n;i++)dis[i]=INF;
    dis[s]=0;
    for(i=1;i<=n;i++){
	long long md=INF;
	int mp=-1;
	for(j=1;j<=n;j++)if(!vis[j]&&dis[j]<md){
	    md=dis[j];
	    mp=j;
	}
	if(mp==-1)break;
	vis[mp]=1;
	for(j=1;j<=n;j++)if(canr[mp][j]){
	    dis[j]=min(dis[j],dis[mp]+co[mp]);
	}
    }
    if(vis[e])printf("%I64d\n",dis[e]);
    else puts("-1");
}