#include <iostream>

using namespace std;
int main(){
	string s;
	int t=1;
	cin>>s;
	for (int i=1; i<=s.size(); i++){
		//cout<<t<<endl;
		if (t>=7){
			cout<<"YES";
			return 0;
		}
		if (s[i]==s[i-1]){
			t+=1;
		}
		else{
			t=1;
		}
	}
	cout<<"NO";
}