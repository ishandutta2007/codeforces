#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,n,m,i,s,l,j,k;
	cin>>x;
	for(i=0;i<x;i++){
		cin>>n>>m;
		l=n%m;
		s=n/m;
		for(j=0;j<l;j++){
			for(k=0;k<s+1;k++)cout<<char(97+j);
		}
		for(j=l;j<m;j++){
			for(k=0;k<s;k++)cout<<char(97+j);
		}
		cout<<endl;
	}
	return 0;
}