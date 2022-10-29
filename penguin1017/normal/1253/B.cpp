#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=1e6+9;
int a[N],sum[N],vis[N];
int ans[N],cnt;
bool check(int l,int r){
	if((r-l+1)&1)return 0;
	rep(i,l,r+1){
		//	cout<<"ok\n";
		if(a[i]>0)++sum[a[i]],++vis[a[i]];
		else {
			if(!sum[-a[i]])return 0;
			--sum[-a[i]];
		}
	}
	rep(i,l,r+1){
		if(a[i]>0){
			if(sum[a[i]])return 0;
			if(vis[a[i]]>1)return 0;
		}
	}
	return 1;
}
void init(int l,int r){
	rep(i,l,r+1){
		if(a[i]>0)sum[a[i]]=0,vis[a[i]]=0;
	}
}
int main(){
	int n,tot=0;
	scanf("%d",&n);
	rep(i,0,n)scanf("%d",&a[i]);
	for(int i=0,last;i<n;i=last+1){
		for(last=i;last<n;++last){
			if(a[last]>0)++tot;
			else --tot;
		//	cout<<a[last]<<' '<<tot<<"tot\n";
			if(tot==0)break;
		}
	//	cout<<i<<' '<<last<<"check\n";
		if(!check(i,last)){
			printf("-1");
			return 0;
		}
		ans[cnt++]=last-i+1;
		init(i,last);
	}
	printf("%d\n",cnt);
	rep(i,0,cnt)printf("%d ",ans[i]);
}