#include <iostream>
#include <string>
using namespace std;
int g(int n){
	if (n==1){
		return 1;
	}
	else{
		int t=1,a;
		a=n;
		while(a%2==0){
			a/=2;
			t+=1;
		}
		return t+g(n-1);
	}
	return 0;
}
int main(){
	int t=0,to_s=0,to_f=0;
	char city;
	string s;
	cin>>t;
	cin>>s;
	city=s[0];
	for (int i=0; i<t; i++){
		if (city!=s[i]){
			if (s[i]=='F'){
				to_f+=1;
				//cout<<22;
			}
			else{
				to_s+=1;
				//cout<<1;
			}
		}
		if (i<t-1)
		city=s[i];
	}
	//cout<<to_s<<endl<<to_f<<endl;
	if (to_f>to_s){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
}