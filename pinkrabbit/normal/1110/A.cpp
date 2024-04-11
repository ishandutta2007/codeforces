#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define MN 100005
int b,k;
int a[MN];
int main(){
	scanf("%d%d",&b,&k);
	F(i,1,k)scanf("%d",a+i);
	if(b%2==0)puts(a[k]%2==0?"even":"odd");
	else{
		int s=0;
		F(i,1,k)s^=a[i]&1;
		puts(s?"odd":"even");
	}
	return 0;
}