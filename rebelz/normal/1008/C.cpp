#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int n;
int a[100005],b[100005];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	int now=n,ans=0;
	for(int i=n;i>=1;i--)
		if(b[now]>a[i])
			ans++,now--;
	cout<<ans<<endl;
	return 0;
}