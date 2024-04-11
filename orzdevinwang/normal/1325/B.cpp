#include<bits/stdc++.h>
using namespace std;
int T,k,n,ans;
int main() {
	scanf("%d",&T);
	while(T--) {
		ans=0;
		map<int,int> ma;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++) scanf("%d",&k),ans+=1-ma[k],ma[k]=1;
		printf("%d\n",ans);
	}
	return 0;
}