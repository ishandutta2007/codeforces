#include<bits/stdc++.h> 
#define M 19
#define N 400010
using namespace std;
int Q,t,cnt,i,RR,deep[N];
long long p,q,R,W,ans;
int max1[M+2][N],fa[M+2][N],dad[M+2][N];
long long sum[N];
int main(){
	scanf("%d",&Q);
	deep[cnt=1]=1;
	while(Q--){
		scanf("%d%I64d%I64d",&t,&p,&q);
		if(t==1){
			R=p^ans;
			W=q^ans;
			dad[0][++cnt]=R;
			max1[0][cnt]=W;
			RR=R;
			for(i=M-1;i>=0;i--)
				if(max1[i][RR]<W)RR=dad[i][RR];
			for(i=1;i<M;i++){
				dad[i][cnt]=dad[i-1][dad[i-1][cnt]];
				max1[i][cnt]=max(max1[i-1][cnt],max1[i-1][dad[i-1][cnt]]);
			}
			fa[0][cnt]=RR;
			sum[cnt]=sum[RR]+W;
			deep[cnt]=deep[RR]+1;
			for(i=1;i<M;i++)
				fa[i][cnt]=fa[i-1][fa[i-1][cnt]];
		}else{
			R=p^ans;
			W=q^ans;
			RR=R;
			for(i=M-1;i>=0;i--)
			if(sum[RR]-sum[fa[i][RR]]<=W){
				W-=sum[RR]-sum[fa[i][RR]];
				RR=fa[i][RR];
			}
			printf("%d\n",ans=deep[R]-deep[RR]);
		}
	}
}