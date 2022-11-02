#include<bits/stdc++.h>
using namespace std;
int n,t;
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		int res=0;
		while (n){
			res=max(res,n%10);
			n/=10;
		}
		printf("%d\n",res);
	}
}