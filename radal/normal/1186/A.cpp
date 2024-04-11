#include <iostream>
using namespace std;
int t[99];
int main(){
	int n,min,m,k;
	cin>>n>>m>>k;
	if (m<k){
		min=m;
	}
	else{
		min=k;
	}
	if (min>=n){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}