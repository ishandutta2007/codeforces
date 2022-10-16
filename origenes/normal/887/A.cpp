#include <iostream>
using namespace std;
int main(){
	string s;
	int cnt=0;
	cin>>s;
	for(int i=0; i<s.length(); i++){
		if(s.at(i)=='1'){
			for(int j=i+1; j<s.length(); j++){
				if(s.at(j)=='0') cnt++;
				if(cnt==6){
					cout<<"yes"<<endl;
					return 0;
				}
			}
			cout<<"no"<<endl;
			return 0;
		}
	}
	cout<<"no"<<endl;
	return 0;
}