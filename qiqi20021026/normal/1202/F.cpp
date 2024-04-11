#include<bits/stdc++.h>

using namespace std;

int a,b,n,ans;

void solve(int m){
	int la=(a+m)/(m+1),ra=a/m,lb=(b+m)/(m+1),rb=b/m;
	if (la>ra||lb>rb) return;
	int l=max(la+lb,n/(m+1)+1),r=min(ra+rb,n/m);
	ans+=l<=r?r-l+1:0;
}

int main(){
	scanf("%d%d",&a,&b); n=a+b;
	for (int i=1;i*i<=n;++i){
		solve(i);
		if (i!=n/i) solve(n/i);
	}
	printf("%d\n",ans);
	
	return 0;
}