#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n,k;
int a[100005];

int gcd(int x,int y){
	if(y==0)
		return x;
	return gcd(y,x%y);
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int now=k;
	for(int i=1;i<=n;i++)
		now=gcd(now,a[i]);
	cout<<k/now<<endl;
	for(int i=0;i<k;i+=now)
		cout<<i<<' ';
	cout<<endl;
	return 0;
}