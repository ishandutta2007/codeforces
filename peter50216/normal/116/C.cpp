#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int pre[3010];
int dis[3010];
int outd[3010];
int que[3010],qs,qe;
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
	scanf("%d",&pre[i]);
	if(pre[i]!=-1)outd[pre[i]]++;
    }
    for(i=1;i<=n;i++)if(outd[i]==0)que[qe++]=i;
    int ans=0;
    while(qs<qe){
	int np=que[qs++];
	if(pre[np]!=-1){
	    outd[pre[np]]--;
	    if(outd[pre[np]]==0){
		dis[pre[np]]=dis[np]+1;
		ans=max(ans,dis[np]+1);
		que[qe++]=pre[np];
	    }
	}
    }
    printf("%d\n",ans+1);
}