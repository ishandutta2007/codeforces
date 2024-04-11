#include <iostream>
using namespace std;
int bar(int a){
	long long int s=0;
	while (a>0){
		s*=10;
		s+=a%10;
		a/=10;
	} 
	
	return s;
}
int sef(int n){
	long long int s=0;
	while (n!=0){
		if (n%10!=0){
			s*=10;
			s+=n%10;
		}
		n/=10;
	}
	return bar(s);
}
int main(){
	long long int n,m,s;
	cin>>n>>m;
	if (n==m){
		cout<<"YES";
		return 0;
	}
	s=m+n;
	if (sef(n)+sef(m)==sef(s)){
		cout<<"YES";
	} 
	else{
		cout<<"NO";
	}
}