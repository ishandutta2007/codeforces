#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n%2==0){
		cout<<"NO";return 0;
	}
	cout<<"YES"<<'\n';
	cout<<"1 ";
	for(int i=0;i<n/2;i++){
		cout<<i*4+4<<' '<<i*4+5<<' ';
	}
	cout<<"2 ";
	for(int i=0;i<n/2;i++){
		cout<<i*4+3<<' '<<i*4+6<<' ';
	}
	return 0;
}