#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t,n;
	cin>>t>>n;
	if (t>n){
		cout<<n<<' '<<(t-n)/2;
	}
	else{
		cout<<t<<' '<<(n-t)/2;
	}
}