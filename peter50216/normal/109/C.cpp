#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n;
struct XD{
    int y,d;
    XD(int yy=-1,int dd=-1):y(yy),d(dd){}
};
vector<XD> ed[101000];
inline bool isl(int n){
    while(n){
	if(n%10==4||n%10==7)n/=10;
	else return 0;
    }
    return 1;
}
int cntd[101000];
int cntp[101000];
int ch[101000];
int pre[101000];
inline void dfs(int np,int p){
    int i;
    ch[np]=1;
    pre[np]=p;
    cntd[np]=0;
    for(i=0;i<ed[np].size();i++){
	int y=ed[np][i].y;
	if(y==p)continue;
	dfs(y,np);
	ch[np]+=ch[y];
	if(ed[np][i].d)cntd[np]+=ch[y];
	else cntd[np]+=cntd[y];
    }
}
inline void dfs2(int np,int p){
    int i;
    for(i=0;i<ed[np].size();i++){
	int y=ed[np][i].y;
	if(y==p)continue;
	if(ed[np][i].d)cntp[y]=n-ch[y];
	else{
	    cntp[y]=cntp[np]+cntd[np]-cntd[y];
	}
	dfs2(y,np);
    }
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	a--;b--;
	c=isl(c);
	ed[a].push_back(XD(b,c));
	ed[b].push_back(XD(a,c));
    }
    dfs(0,-1);
    dfs2(0,-1);
    long long ans=0;
    for(i=0;i<n;i++){
	int r=cntd[i]+cntp[i];
	//printf("%d %d\n",i,r);
	ans+=(long long)r*(r-1ll);
    }
    printf("%I64d\n",ans);
}