#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,b,a) for(int i=b-1;i>=a;i--)
#define N (int)2e5+9
using namespace std;
int a[N],op[N],p[N],x[N],vis[N];
int main()
{
	int n,q;
	scanf("%d",&n);
	rep(i,1,n+1){
		scanf("%d",&a[i]);
	}
	scanf("%d",&q);
	rep(i,0,q){
		scanf("%d",&op[i]);
		if(op[i]==1){
			scanf("%d%d",&p[i],&x[i]);
		}
		else scanf("%d",&x[i]);
	}
	int maxn=0;
	per(i,q,0){
		if(op[i]==2)maxn=max(maxn,x[i]);
		else{
			if(!vis[p[i]])a[p[i]]=max(maxn,x[i]),vis[p[i]]=1;
		}
	}
	rep(i,1,n+1)if(!vis[i])a[i]=max(a[i],maxn);
	rep(i,1,n+1)printf("%d ",a[i]);
 }