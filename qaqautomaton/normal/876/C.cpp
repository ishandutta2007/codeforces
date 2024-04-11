#include<bits/stdc++.h>
using namespace std;
int a[102424],tot;
int sum(int x){
	int tot=0;
	while(x){
		tot+=x%10;
		x/=10;
	}
	return tot;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<=81;++i){
		if(sum(n-i)==i)a[++tot]=n-i;
	}
	printf("%d\n",tot);
	while(tot){
		printf("%d\n",a[tot]);
		--tot;
	}
	return 0;
}