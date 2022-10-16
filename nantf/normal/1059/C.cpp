#include<bits/stdc++.h>
using namespace std;
void AONYAPAEEMIA(int x,int fac){
	if(x==1) return void(printf("%d ",fac));
	if(x==2) return void(printf("%d %d ",fac,2*fac));
	if(x==3) return void(printf("%d %d %d ",fac,fac,3*fac));
	for(int i=1;i<=(x+1)/2;i++) printf("%d ",fac);
	AONYAPAEEMIA(x/2,fac*2);
}
int n;
int main(){
	scanf("%d",&n);
	AONYAPAEEMIA(n,1);
}