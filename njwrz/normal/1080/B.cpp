#include<bits/stdc++.h>
using namespace std;
int main(){
	long long x,n,m,i,k,s;
	cin>>x;
	for(k=0;k<x;k++){
		cin>>n>>m;
		n--;
		s=m/2-n/2;
		if(n%2==1)s+=n;
		if(m%2==1)s-=m;
		cout<<s<<endl;
	}
	return 0;
}