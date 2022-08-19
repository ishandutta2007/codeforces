#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

int n;
int a[55],b[55];

int main(){
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		s-=b[i];
	}
	if(s>=0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}