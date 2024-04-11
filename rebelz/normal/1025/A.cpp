#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n;
bool flag[200005];

int main(){
	cin>>n;
	if(n==1){
		cout<<"YES"<<endl;
		return 0;
	}
	char x;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(flag[x]){
			cout<<"YES"<<endl;
			return 0;
		}
		else
			flag[x]=true;
	}
	cout<<"NO"<<endl;
	return 0;
}