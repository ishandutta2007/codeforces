#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int n,k;
int a[200005],p[1000005];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]++;
	}
	int ans=n;
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n-1;i++)
		if(a[i]+k>=a[i+1])
			ans-=p[a[i]];
	cout<<ans<<endl;
	return 0;
}