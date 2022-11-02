#include<stdio.h>
#include<limits.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
struct XD{
    int x,y,g,s;
    void input(){scanf("%d%d%d%d",&x,&y,&g,&s);}
    bool operator<(const XD& b)const{
	return g<b.g;
    }
}ed[50010];
int pre[300];
inline int find(int a){return pre[a]==-1?a:pre[a]=find(pre[a]);}

bool cmp(const XD& a,const XD& b){return a.s<b.s;}
bool del[50010];
int main(){
    int n,m,i,j;
    long long gc,sc;
    scanf("%d%d%I64d%I64d",&n,&m,&gc,&sc);
    for(i=0;i<m;i++)ed[i].input();
    sort(ed,ed+m);
    long long ans=LONG_LONG_MAX;
    int r=0;
    for(i=0;i<m;i++){
	int gg=ed[i].g;
	ed[r++]=ed[i];
	inplace_merge(ed,ed+r-1,ed+r,cmp);
	for(j=1;j<=n;j++)pre[j]=-1;
	int cnt=0;
	for(j=0;j<r;j++)del[j]=0;
	for(j=0;j<r;j++){
	    int xx=find(ed[j].x),yy=find(ed[j].y);
	    if(xx!=yy){
		pre[xx]=yy;
		cnt++;
	    }else del[j]=1;
	    if(cnt==n-1)break;
	}
	if(cnt==n-1){
	    ans=min(ans,gg*gc+ed[j].s*sc);
	}
	int k;
	for(j=0,k=0;j<r;j++){
	    if(!del[j])ed[k++]=ed[j];
	}
	r=k;
    }
    printf("%I64d\n",ans==LONG_LONG_MAX?-1:ans);
}