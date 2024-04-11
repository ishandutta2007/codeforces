#include<bits/stdc++.h>

using namespace std;

int n,m;

int main(){
	scanf("%d",&m);
	while (m--){
		scanf("%d",&n);
		int x=n+1;
		if ((x&(-x))==x){
			bool fl=0;
			for (int i=2;i*i<=n;++i)
				if (n%i==0){
					printf("%d\n",n/i);
					fl=1;
					break;
				}
			if (!fl) puts("1");
		}
		else{
			int t=1;
			for (;t<x;t*=2);
			printf("%d\n",t-1);
		}
	}
	
	return 0;
}