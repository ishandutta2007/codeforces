#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int n,x;
int a[100005],c[100005];

int main(){
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(c[a[i]]==1){
			cout<<0<<endl;
			return 0;
		}
		c[a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if((a[i]&x)!=a[i]&&c[a[i]&x]==1){
			cout<<1<<endl;
			return 0;
		}
	}
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++){
		if(c[a[i]&x]==1){
			cout<<2<<endl;
			return 0;
		}
		c[a[i]&x]=1;
	}
	cout<<-1<<endl;
	return 0;
}