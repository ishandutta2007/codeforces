#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,t=0;
	string s;
	cin>>n>>s;
	for (int i=1; i<n; i++){
		if (s[i]==s[i-1]){
			t+=1;
		}
	}
	cout<<t;
}