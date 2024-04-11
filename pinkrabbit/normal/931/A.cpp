#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	if(a>b) swap(a,b);
	int md=a+b>>1;
	printf("%d",(md-a)*(md-a+1)/2+(b-md)*(b-md+1)/2);
	return 0;
}