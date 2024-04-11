#include <iostream>
using namespace std;
int factor(int n){
	int z=1;
	for (int i=2; i<=n; i++){
		z*=i;
	}
	return z;
}
int count(string a,char c){
	int t=0;
	for (int i=0; i<a.size(); i++){
		if (a[i]==c){
			t+=1;
		}
	}
	return t;
}
int main(){
	string s;
	cin>>s;
	if (count(s,'a')>s.size()/2){
		cout<<s.size();
	}
	else{
		int b;
		if (s.size()%2==1){
			b=s.size()/2+1;
		}
		else{
			b=s.size()/2;
		}
		cout<<2*count(s,'a')-1;
	}
}