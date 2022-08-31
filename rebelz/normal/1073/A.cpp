#include<bits/stdc++.h>

using namespace std;

int n,x;
char a[200005];

int main(){
	cin>>n;
	char ch;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			cout<<"YES"<<endl;
			cout<<a[i-1]<<a[i]<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}