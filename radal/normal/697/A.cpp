#include <iostream>
using namespace std;
int main(){
	unsigned long long int s,x,t;
	cin>>t>>s>>x;
	if (x==t){
		cout<<"YES";
		return 0;
	}
	if (x<t){
		cout<<"NO";
		return 0;
	}
	x-=t;
	if ((x%s==0 || x%s==1) and x>=s ){
		cout<<"YES";
		return 0;
	}
	cout<<"NO";
	
	
}