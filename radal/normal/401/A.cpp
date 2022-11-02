#include <iostream>
using namespace std;
int main(){
	int n,x,m,t;
	m=0;
	t=1;
	cin>>n>>x;
	for (int i=1; i<=n; i++){
		int z;
		cin>>z;
		m+=z;
	}
	if (m==0){
		cout<<0;
		return 0;
	}
	if (m<0){
		while (m<-x){
			t+=1;
			m+=x;
		}
	}
	if (m>0){
		while (m>x){
			t+=1;
			m-=x;
		}
	}
	cout<<t;
}