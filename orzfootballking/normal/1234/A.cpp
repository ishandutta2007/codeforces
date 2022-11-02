#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,n,t,sum;
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>x;sum=0;
		for(int i=0;i<x;i++){
			cin>>n;sum+=n;
		}
		cout<<sum/x+(sum%x!=0)<<'\n';
	}
	return 0;
}