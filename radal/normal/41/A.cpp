#include <iostream>
#include <algorithm>
using namespace std;
bool friends(int a,int b){
	if (a%b==0 || b%a==0){
		return 1;
	}
	return 0;
}
int main(){
	string a,b;
	cin>>a>>b;
	reverse(a.begin(),a.end());
	if (a==b){
		cout<<"YES";
		return 0;
	}
	cout<<"NO";
}