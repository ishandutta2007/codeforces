#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int x[100100],y[100100];
vector<int> nex[100100];
int miny[100100];
const int inf=1000000000;
inline int ABS(int a){return a>0?a:-a;}
int main(){
    int n,m,i,j;
    scanf("%d%d%*d%*d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&x[i]);
    for(i=0;i<m;i++)scanf("%d",&y[i]);
    j=0;
    for(i=0;i<n;i++){
	if(j<0)j=0;
	while(j<m&&y[j]<=x[i])j++;
	j--;
	int mm=inf;
	if(j>=0)mm=min(mm,x[i]-y[j]);
	if(j<m-1)mm=min(mm,y[j+1]-x[i]);
	if(j>=0&&x[i]-y[j]==mm)nex[i].push_back(j);
	if(j<m-1&&y[j+1]-x[i]==mm)nex[i].push_back(j+1);
    }
    int ans=0;
    for(i=0;i<m;i++)miny[i]=inf;
    for(i=0;i<n;i++){
	if(nex[i].size()==0)while(1)puts("!");
	if(nex[i].size()==1||miny[nex[i][0]]==inf||miny[nex[i][0]]==ABS(x[i]-y[nex[i][0]])){
	    miny[nex[i][0]]=min(miny[nex[i][0]],ABS(x[i]-y[nex[i][0]]));
	}else{
	    miny[nex[i][1]]=min(miny[nex[i][1]],ABS(x[i]-y[nex[i][1]]));
	}
    }
    for(i=0;i<n;i++){
	for(j=0;j<nex[i].size();j++){
	    int q=nex[i][j];
	    if(ABS(x[i]-y[q])==miny[q])break;
	}
	if(j==nex[i].size())ans++;
    }
    printf("%d\n",ans);
}