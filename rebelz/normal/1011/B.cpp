#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n,m;
int a[105],t[105];

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	int l=0;
	for(int i=1;i<=m/n;i++){
		int ans=0;
		for(int j=1;j<=100;j++)
			ans+=t[j]/i;
		if(ans>=n)
			l=i;
	}
	cout<<l<<endl;
	return 0;
}