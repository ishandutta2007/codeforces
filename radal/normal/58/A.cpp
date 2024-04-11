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
	int j=0;
	b="hello";
	cin>>a;
	for (int i=0; i<a.size(); i++){
		if (a[i]==b[j]){
			if (b[j]=='o'){
				cout<<"YES";
				return 0;
			}
			j+=1;
		}
	}
	cout<<"NO";
}