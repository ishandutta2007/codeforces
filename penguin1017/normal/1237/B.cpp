#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define lowbit(x) ((x)&(-x))
using namespace std;
const int N=(int)1e5+9;
int sum[N],a[N],b[N],pos[N];
void Set(int p,int val){
	for(int i=p;i<N;i+=lowbit(i))sum[i]+=val;
}
int Get(int p){
	int res=0;
	for(int i=p;i;i^=lowbit(i))res+=sum[i];
	return res; 
}
int main()
{
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&a[i]);
	rep(i,1,n+1){
		scanf("%d",&b[i]);
		pos[b[i]]=i;
		Set(i,1);
	} 
	int ans=0;
	per(i,1,n+1){
		if(Get(pos[a[i]])<i)ans++;
		Set(pos[a[i]],-1);
	}
	printf("%d",ans);
}