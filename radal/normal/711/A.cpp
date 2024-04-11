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
	int n,j;
	bool k=0;
	cin>>n;
	string  d[n];
	for (int i=0; i<n; i++){
		string s;
		cin>>s;
		if (s[0]==s[1] and s[0]=='O' and k==0){
			s[0]='+';
			s[1]='+';
			j=i;
			k=1;
		}
		if (s[3]==s[4] and s[3]=='O' and k==0){
			s[3]='+';
			s[4]='+';
			j=i;
			k=1;
		}
		d[i]=s;
	}
	if (not k){
		cout<<"NO";
	}
	else{
		cout<<"YES"<<endl;
		for (int i=0; i<n; i++){
			cout<<d[i]<<endl;
		}
	}
}