#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef long long ll;
ll n,h,ans;
ll s[200005],x1[200005],x2[200005];

void divide(int l,int r,int x){
	if(l>r)
		return;
	int mid=(l+r)/2;
	if(s[mid]-s[x]<h){
		ans=mid;
		divide(mid+1,r,x);
	}
	else
		divide(l,mid-1,x);
}

int main(){
	cin>>n>>h;
	for(int i=1;i<=n;i++)
		cin>>x1[i]>>x2[i];
	for(int i=2;i<=n;i++)
		s[i]=s[i-1]+x1[i]-x2[i-1];
	ll maxa=-1;
	for(int i=1;i<=n;i++){
		divide(i,n,i);
		maxa=max(maxa,h-s[ans]+s[i]+x2[ans]-x1[i]);
	}
	cout<<maxa<<endl;
	return 0;
}