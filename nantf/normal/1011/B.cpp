#include<iostream>  //
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[101],cnt[101],maxn=0;
bool check(int x){
	if(!x) return true;
	int sum=0;
	for(int i=1;i<=100;i++) sum+=cnt[i]/x;
	return sum>=n;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",a+i);cnt[a[i]]++;maxn=max(maxn,cnt[a[i]]);
	}
	int l=0,r=maxn,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
}