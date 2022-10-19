#include<bits/stdc++.h>

using namespace std;

int n,m,x[120000],ans;

int main(){
	scanf("%d%d",&n,&m);
	for (int i=m-1;~i;--i) scanf("%d",x+i);
	for (int i=0,t=1;i<m;++i){
		ans=(ans+t*x[i])%2;
		t=t*n%2;
	}
	puts(ans?"odd":"even");
	
	return 0;
}