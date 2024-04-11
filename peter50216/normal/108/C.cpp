#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct XD{
    int y,d;
    XD(int yy=0,int dd=0):y(yy),d(dd){}
};
vector<XD> ed[1010];
int ind[1010],outd[1010];
int main(){
    int n,m,i;
    scanf("%d%d",&n,&m);
    while(m--){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	ed[a].push_back(XD(b,c));
	ind[b]++;
	outd[a]++;
    }
    int cnt=0;
    for(i=1;i<=n;i++)if(ind[i]==0&&outd[i]==1)cnt++;
    printf("%d\n",cnt);
    for(i=1;i<=n;i++)if(ind[i]==0&&outd[i]==1){
	printf("%d ",i);
	int np=i;
	int md=10000000;
	while(ed[np].size()){
	    md=min(md,ed[np][0].d);
	    np=ed[np][0].y;
	}
	printf("%d %d\n",np,md);
    }
}