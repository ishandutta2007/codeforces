#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef long long ll;
ll n,l,a;

int main(){
	cin>>n>>l>>a;
	ll last=0,ans=0,x,y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		ans+=(x-last)/a;
		last=x+y;
	}
	cout<<ans+(l-last)/a<<endl;
	return 0;
}