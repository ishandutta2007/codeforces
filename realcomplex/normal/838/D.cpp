#include <bits/stdc++.h>

using namespace std;

#define mod ((int)1e9+7)

int reiz(int a,int b){
	return (1LL*a*b)%mod;
}

int power(int n,int k){
	if(k==0)
		return 1;
	int l = power(n,k/2);
	if(k%2==0)
		return reiz(l,l);
	if(k%2==1)
		return reiz(reiz(l,l),n);
}

int main(){
	int n,m;
	cin >> n >> m;
	cout << reiz(reiz(power(n+1,m-1),n-m+1),power(2,m));
	return 0;
}