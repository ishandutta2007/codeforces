#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=1e5+9;
int a[N],L[N],R[N];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&a[i]);
	int maxn=0;
	L[0]=1;
	rep(i,1,n+1){
		if(a[i]>a[i-1])L[i]=L[i-1];
		else L[i]=i;
		maxn=max(i-L[i],maxn);
	}
	R[n+1]=n;
	per(i,1,n+1){
		if(a[i]>a[i+1])R[i]=R[i+1];
		else R[i]=i;
		maxn=max(R[i]-i,maxn);
	}
	int ans=0;
	//cout<<maxn<<"check\n";
	int sum=0;
	rep(i,1,n+1){
		int l=i-L[i],r=R[i]-i;
		sum+=l==maxn;
		sum+=r==maxn;
		if(l!=r)continue;
		if(r!=maxn)continue;
		if(maxn-1&1)ans++;
	}
	if(sum>2)ans=0;
	cout<<ans;
}