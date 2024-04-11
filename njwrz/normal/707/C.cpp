#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,t=1,m;
	cin>>n;
	m=n;
	while(m%2==0){
		m=m/2;
	}
	if(m!=1){
		t=n/m;
		cout<<m*m/2*t<<' '<<m*m/2*t+t;
	}else{
		if(n>=4){
			cout<<n/4*3<<' '<<n/4*5;
		}else{
			cout<<-1;
		}
	}
	return 0;
}