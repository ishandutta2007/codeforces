#include<bits/stdc++.h>
using namespace std;
int l,r,a;
int main(){
	scanf("%d%d%d",&l,&r,&a);
	if(l>r) swap(l,r);
	if(l+a<=r) {printf("%d",(l+a)*2); return 0;}
	printf("%d",(l+a+r)/2*2);
	return 0;
}