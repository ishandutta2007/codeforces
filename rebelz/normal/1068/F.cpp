#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=(2*n-1)/3+1;i++)
		printf("1 %d\n",i);
	for(int i=1;i<=n-(2*n-1)/3-1;i++)
		printf("4 %d\n",2*i);
	return 0;
}