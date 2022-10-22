#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,s=0,p=0;
	cin>>n>>m;
	m=m*2+1;
	if(n%m==0){
		cout<<n/m;
	}else cout<<n/m+1;
	cout<<endl;
	while(s<n){
		s+=m;
		if(s-m/2>n)p=s-m/2-n;
	} 
	s=0;
	while(s<n){
		s+=m;
		cout<<s-m/2-p<<" ";
	}
	return 0;
}