#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=(int)2e5+9;
int sum1[N],sum2[N],sum3[N],cost1[N],cost3[N];
int main()
{
	int k1,k2,k3,val,n;
	scanf("%d%d%d",&k1,&k2,&k3);
	n=k1+k2+k3;
	rep(i,0,k1)scanf("%d",&val),++sum1[val];
	rep(i,0,k2)scanf("%d",&val);
	rep(i,0,k3)scanf("%d",&val),++sum3[val];
	rep(i,1,n+1)sum1[i]+=sum1[i-1],sum3[i]+=sum3[i-1];
	rep(i,0,n+1){
		cost1[i]=sum1[n]-sum1[i]+i-(sum1[i]+sum3[i]);
	}
	per(i,1,n+1){
		cost3[i]=(n-i+1)-(sum3[n]+sum1[n]-sum3[i-1]-sum1[i-1])+sum3[i-1];
	}
	cost3[n+1]=sum3[n];
	per(i,1,n+1)cost3[i]=min(cost3[i],cost3[i+1]);
	int ans=n;
	rep(i,0,n+1)ans=min(ans,cost1[i]+cost3[i+1]);
	printf("%d",ans);
}