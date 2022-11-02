#include <iostream>
using namespace std;
int t[99];
int main(){
	int n,b=0,j=0;
	cin>>n;
	for (int i=0; i<=99; i++){
		t[i]=0;
	}
	for (int i=0; i<n; i++){
		int m;
		cin>>m;
		t[m-1]+=1;
	}
	b=t[0];
	for (int i=0; i<=99; i++){
		if (t[i]>b){
			b=t[i];
			j=i;
		}
	}
	cout<<b;
}