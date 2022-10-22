#include <bits/stdc++.h>
using namespace std;
int main(){
	double n,m,k;
	cin>>n>>m>>k;
	int t=(k/100)*(n*m);
	int x=n;
	for(int i=0;i<x;i++){
		if(t>=m){
			cout<<m;t-=m;
		}else if(t!=0){
			cout<<t;t=0;
		}else{
			cout<<0;
		}
		cout<<' ';
	}
	return 0;
}