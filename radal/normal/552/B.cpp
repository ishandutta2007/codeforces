#include <iostream>
#include <cmath>
using namespace std;
int main(){
	unsigned long long int n,t,n1,m,m2;
	cin>>n;
	n1=n;
	t=0;
	m=0;
	m2=0;
	while (n1!=0){
		t+=1;
		n1=n1/10;
	}
	for (short int i=t; i>0; i--){
		if (i==t){
			m+=i*(n-pow(10,t-1)+1);
		}
		else{
			m+=i*(pow(10,i)+1-(pow(10,i-1)));
		}
	}
	for (int i=1; i<t; i++){
		m2+=i;
	}
	cout<<m-m2;
}