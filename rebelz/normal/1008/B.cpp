#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n;
int a[100005],b[100005];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	int now=1<<30;
	for(int i=1;i<=n;i++){
		if(a[i]>b[i])
			swap(a[i],b[i]);
		if(b[i]<=now)
			now=b[i];
		else if(a[i]<=now)
			now=a[i];
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}