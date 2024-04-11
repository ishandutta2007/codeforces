#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	string j[n];
	for (int i=0; i<n; i++){
		string s;
		cin>>s;
		if (s[s.size()-1]=='o'){
			j[i]="FILIPINO";
		}
		if (s[s.size()-1]=='u'){
			j[i]="JAPANESE";
		}
		if (s[s.size()-1]=='a'){
			j[i]="KOREAN";
		}
	}
	for (int i=0; i<n; i++){
		cout<<j[i]<<endl;
	}
}