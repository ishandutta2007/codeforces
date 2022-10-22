#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin>>k>>n>>m;
	if(n==k-1&&k!=1){
		cout<<-1;return 0;
	}
	cout<<"1 ";
	int s=1;
	for(int i=0;i<m;i++){
		cout<<s*2<<' ';
		s*=2;
	}
	for(int i=1;i<k-n-m;i++){
		cout<<s<<' ';
	}
	for(int i=0;i<n;i++)cout<<++s<<' ';
	return 0;
}