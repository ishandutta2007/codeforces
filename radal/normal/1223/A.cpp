#include <iostream>
using namespace std;
int main(){
	int q;
	cin>>q;
	int j[q];
	for (int i=0; i<q; i++){
		int n;
		cin >>n;
		if (n==0){
			j[i]=4;
			continue;
		}
		if (n==1){
			j[i]=3;
			continue;
		}
		if (n==2){
			j[i]=2;
			continue;
		}
		if (n%2==1 and n!=1){
			j[i]=1;
			continue;
		}
		if (n%2==0 and n!=0 and n!=2){
			j[i]=0;
		}
	}
	for (int i=0; i<q; i++){
		cout<<j[i]<<endl;
	}
}