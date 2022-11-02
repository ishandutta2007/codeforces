#include<bits/stdc++.h> 
using namespace std; 

int GCD(long long int a, long long int b){
	if (b!=0){
		return GCD(b,a%b);
	}
	else{
		return a;
	}
}
int main(){
	int m,n,t=0;
	cin>>n>>m;
	while (min(n,m)>0 && max(n,m)>1){
		if (n<m){
			n--;
			m-=2;
		}
		else{
			m--;
			n-=2;
		}
		t++;
	}
	cout<<t;
}