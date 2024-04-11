#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,m,ans,a[N];

int main(){
	scanf("%d%d",&n,&m);
	if (n>m){puts("0"); return 0;}
	for (int i=1;i<=n;++i){
		scanf("%d",a+i);
	}
	ans=1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<i;++j)
			ans=ans*(abs(a[i]-a[j])%m)%m;
	printf("%d\n",ans);
	
	return 0;
}