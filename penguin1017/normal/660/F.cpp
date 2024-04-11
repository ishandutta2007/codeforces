#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long 
using namespace std;
const int N=(int)2e5+9;
ll a[N],dp[N],st[N],ans;
void upd(ll &a,ll b){
	if(a<b)a=b; 
}
ll get(int i,int j){
	return dp[i]-dp[j]-j*(a[i]-a[j]);
}
ll get2(int i,int j){
	return i*a[i]-dp[i]-(j*a[j]-dp[j]);
}
int main()
{
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%lld",&a[i]),dp[i]+=dp[i-1]+i*a[i],a[i]+=a[i-1],upd(ans,dp[i]);
	int head=0;
	rep(i,1,n+1){
		int l=0,r=head-1,t=head;
		while(l<=r){
			int mid=(l+r)>>1;
			if(get(i,st[mid])>=get(i,st[mid+1]))t=mid,r=mid-1;
			else l=mid+1;
		}
		upd(ans,get(i,st[t]));
		while(head&&(get2(i,st[head])*(st[head]-st[head-1])>get2(st[head],st[head-1])*(i-st[head])))head--;
		st[++head]=i;
	}
	printf("%lld",ans);
}