#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n,m;
int a[15],t[15];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int x;
	for(int i=1;i<=m;i++){
		cin>>x;
		t[x]++;
	}
	for(int i=1;i<=n;i++){
		if(t[a[i]]>0){
			cout<<a[i]<<' ';
			t[a[i]]--;
		}
	}
	cout<<endl;
	return 0;
}