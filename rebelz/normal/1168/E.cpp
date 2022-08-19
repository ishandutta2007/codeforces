#include<bits/stdc++.h>

using namespace std;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,ncnt,cnt;
int a[5005],p[5005],q[5005],dp[5005],dq[5005],tmp[5005],emp[5005];

int main(){
	n=1<<readint();
	int sum=0;
	for(int i=1;i<=n;i++) a[i]=readint(),sum^=a[i];
	if(sum) return printf("Fou\n"),0;
	memset(p,-1,sizeof(p));
	memset(q,-1,sizeof(q));
	while(1){
		cnt=0;
		for(int i=1;i<=n;i++) if(p[i]<0) emp[++cnt]=i;
		if(!cnt) break;
		int now=emp[rand()%cnt+1];
		for(int i=0;i<n;i++){
			if(!dp[i]&&!dq[a[now]^i]){
				p[now]=i,q[now]=a[now]^i,dp[i]=now,dq[a[now]^i]=now;
				break;
			}
		}
		if(p[now]<0){
			ncnt=0;
			for(int i=0;i<n;i++) if(!dp[i]) tmp[++ncnt]=i;
			int th=rand()%ncnt+1,g=a[now]^tmp[th];
			p[now]=tmp[th],dp[tmp[th]]=now,q[now]=g,dp[p[dq[g]]]=0,p[dq[g]]=-1,q[dq[g]]=-1,dq[g]=now;
		}
	}
	printf("Shi\n");
	for(int i=1;i<=n;i++) printf("%d ",p[i]);
	printf("\n");
	for(int i=1;i<=n;i++) printf("%d ",q[i]);
	printf("\n");
	return 0;
}