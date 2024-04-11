#include<bits/stdc++.h>
using namespace std;
int n,m,res;
int main(){
	scanf("%d%d",&n,&m);
	res=100003;
	printf("%d %d\n",res,res);
	for (int i=1;i<n-1;i++){
		printf("%d %d 1\n",i,i+1);
		res--;
	}
	printf("%d %d %d\n",n-1,n,res);
	int o,p;
	o=1;p=3;
    for (int i=0;i<m-n+1;i++){
    	printf("%d %d 100000000\n",o,p);
    	p++;
    	if (p>n){
    		o++;
			p=o+2;
    	}
    }
}