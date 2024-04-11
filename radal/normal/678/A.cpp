#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	if (n%k==0){
		cout<<n+k;
	}
	else{
		cout<<n+(k-n%k);
	}
}