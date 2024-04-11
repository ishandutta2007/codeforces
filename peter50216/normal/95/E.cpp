#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int cnt[100010];
int pre[100010];
int cc[100010];
inline int find(int a){if(pre[a]==0)return a;return pre[a]=find(pre[a]);}
int dp[100010];
int dp2[100010];
int lar[100010],lc=0;
bool islucky[100010];
inline void init(int n){
    if(n)islucky[n]=1;
    if(n>=10000)return;
    init(n*10+4);
    init(n*10+7);
}
int que[100010],qs,qe;
int main(){
    init(0);
    int n,m,i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)cc[i]=1;
    while(m--){
	int a,b;
	scanf("%d%d",&a,&b);
	a=find(a);b=find(b);
	if(a!=b){
	    pre[a]=b;
	    cc[b]+=cc[a];
	}
    }
    int nn=(int)sqrt(n);
    for(i=1;i<=n;i++)if(pre[i]==0){
	if(cc[i]<=nn)cnt[cc[i]]++;
	else lar[lc++]=cc[i];
    }
    dp[0]=0;
    const int INF=1000000000;
    for(i=1;i<=n;i++)dp[i]=INF;
    for(i=1;i<=nn;i++){
	int ccc=cnt[i];
	if(ccc==0)continue;
	for(j=0;j<=n;j++)dp2[j]=dp[j];
	for(j=0;j<i;j++){
	    qs=qe=0;
	    for(k=0;k*i+j<=n;k++){
		if(k){
		    int a=dp[que[qs]*i+j]-que[qs];
		    if(a<INF)dp2[k*i+j]=min(dp2[k*i+j],a+k);
		}
		if(qs<qe&&que[qs]==k-ccc)qs++;
		while(qs<qe){
		    if(dp[que[qe-1]*i+j]-que[qe-1]>=dp[k*i+j]-k)qe--;
		    else break;
		}
		que[qe++]=k;
	    }
	}
	for(j=0;j<=n;j++)dp[j]=dp2[j];
    }
    for(i=0;i<lc;i++){
	int ccc=lar[i];
	for(j=n;j>=ccc;j--){
	    dp[j]=min(dp[j],dp[j-ccc]+1);
	}
    }
    int ans=INF;
    for(i=1;i<=n;i++)if(islucky[i]&&ans>dp[i])ans=dp[i];
    if(ans==INF)puts("-1");
    else printf("%d\n",ans-1);
}