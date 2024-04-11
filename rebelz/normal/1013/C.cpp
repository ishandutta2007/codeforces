#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

typedef long long ll;

int n;
ll a[200005];

int main(){
	cin>>n;
	for(int i=1;i<=n+n;i++)
		cin>>a[i];
	sort(a+1,a+n+n+1);
	ll now=1ll<<60;
	for(int i=2;i<=n;i++){
		if(a[i+n-1]-a[i]<now)
			now=a[i+n-1]-a[i];
	}
	if(now*(a[n+n]-a[1])<(a[n]-a[1])*(a[n+n]-a[n+1]))
		cout<<now*(a[n+n]-a[1])<<endl;
	else
		cout<<(a[n]-a[1])*(a[n+n]-a[n+1])<<endl;
	return 0;
}