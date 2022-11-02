#include <iostream>
using namespace std;
int main(){
	long long int k,l,i;
	i=0;
	cin>>k>>l;
	if (k==l){
		cout<<"YES"<<endl;
		cout<<"0";
		return 0;
	}
	if (l%k!=0){
		cout<<"NO";
		return 0;
	}
	while (l>k){
		i+=1;
		l/=k;
	}
	if (l==k){
		cout<<"YES"<<endl;
		cout<<i;
		return 0;		
	} 
	else{
		cout<<"NO";
	}
}