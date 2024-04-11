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
int l[333333],use[333333],x;
int main(){
	int n;
	scanf("%d",&n);
	printf("1 ");
	int sum=1;
	l[n+1]=1;
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		if(l[x+1]){
			l[x]=1;
		}
		if(l[x]){
			int j=x;
			while(use[j-1]){
				--sum;
				--j;
				l[j]=1;
			}
		}
		else{
			++sum;
		}
		use[x]=1;
		printf("%d%c",sum,i==n?'\n':' ');
	}
	return 0;
}