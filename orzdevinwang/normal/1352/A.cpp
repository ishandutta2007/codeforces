#include<bits/stdc++.h>
using namespace std;
int n,k,sp,ans,d[10001];
int main(){
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&k),sp=1,ans=0;
		while(k!=0) {
			sp*=10;
			if(k%sp==0) continue;
			++ans,d[ans]=k%sp,k-=k%sp;
		}
		printf("%d\n",ans);
		for(int i = 1; i <= ans; i++) printf("%d ",d[i]);
		printf("\n");
	}
	return 0;
}