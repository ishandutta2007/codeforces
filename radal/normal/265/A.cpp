#include <iostream>
#include <cmath>
using namespace std;
bool aval(int n){
	int t=1;
	for (int i=2; i<n; i++){
		if (n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	string s,t;
	int p=1;
	cin>>s>>t;
	for (int i=0; i<t.size(); i++){
		if (t[i]==s[p-1]){
			p+=1;
		}
	}
	cout<<p;
}