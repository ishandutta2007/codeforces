#include <iostream>
#include <string>
using namespace std;
int main(){
	long long int n,ta=0,td=0;
	string s;
	cin>>n;
	cin>>s;
	for (int i=0; i<n; i++){
		if (s[i]=='A'){
			ta+=1;
		}
		else{
			td+=1;
		}
	}
	if (ta>td){
		cout<<"Anton";
	}
	if (ta==td){
		cout<<"Friendship";
	}
	if (ta<td){
		cout<<"Danik";
	}
}