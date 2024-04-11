#include<iostream>
using namespace std;
long long dfs(long long n){
	long long i,t=1,s;
	if(n<100){
		for(i=0;i<n;i++){
			t*=2;t%=1000000007;
		}
		return t;
	}
	s=dfs(n/100);
	for(i=0;i<100;i++){
		t*=s;t%=1000000007;
	}
	for(i=0;i<n%100;i++){
		t*=2;t%=1000000007;
	}
	return t;
}
int main(){
	long long n,m;
	cin>>n>>m;
	if(n==0){
		cout<<0;return 0;
	}
	n%=1000000007;
	cout<<(1000000007+n*dfs(m+1)-dfs(m)+1)%1000000007;
	return 0;
}