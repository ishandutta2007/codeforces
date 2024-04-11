#include<bits/stdc++.h>

using namespace std;

int n,m,tmp,p;

int main(){
	p=1000000000;
	scanf("%d%d",&n,&m);
	int i;
	for (i=1;i<=n;++i){
		tmp+=(i-1)/2;
		if (tmp>=m){
			for (int j=1;j<i;++j) printf("%d ",j);
			printf("%d ",i+(tmp-m)*2);
			for (int j=i+1;j<=n;++j) printf("%d ",p-(n-j)*n*2);
			return 0;
		}
	}
	puts("-1");
	
	return 0;
}