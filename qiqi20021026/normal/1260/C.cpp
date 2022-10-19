#include<bits/stdc++.h>

using namespace std;

int t,n,m,k;

int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}

int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d%d%d",&n,&m,&k);
		int g=gcd(n,m);
		n/=g; m/=g;
		if (n<m) swap(n,m);
		if (k==1){puts("REBEL"); continue;}
		puts((n-2)/m+1<k?"OBEY":"REBEL");
	}
	
	return 0;
}