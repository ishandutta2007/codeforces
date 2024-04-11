#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n,maxa=-1,mina=1000000000;
int a[1005];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mina=min(mina,a[i]),maxa=max(maxa,a[i]);
	}
	cout<<maxa-mina-n+1<<endl;
	return 0;
}