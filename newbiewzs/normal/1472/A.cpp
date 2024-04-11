#include<bits/stdc++.h>
using namespace std;
int n,m;
int T,x,y,z;
int ycl[561516];
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x;
		x=x*x;
		k>>=1;
	}
	return base;
}
int main(){
	cin>>T;
	for(int i=2;i<=10000;i+=2){
		ycl[i]=ycl[i/2]+1;
	}
	while(T--){
		scanf("%d%d%d",&x,&y,&z);
		int xx=x;
		int yy=y;
		while(xx%2==0 and xx)xx/=2;
		while(yy%2==0 and yy)yy/=2;
		int zs=(x/xx)*(y/yy);
		if(zs<z)puts("NO");
		else puts("YES"); 
	}
	return 0;
}