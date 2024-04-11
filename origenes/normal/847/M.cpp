#include <iostream>
using namespace std;
int n, t[105];
int main(){
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>t[i];
	bool flag=true;
	int diff=t[2]-t[1];
	for(int i=3; i<=n; i++)
		if(t[i]-t[i-1]!=diff){
			flag=false;
			break;
		}
	if(flag){
		cout<<t[n]+diff<<endl;
	}else{
		cout<<t[n]<<endl;
	}
	return 0;
}