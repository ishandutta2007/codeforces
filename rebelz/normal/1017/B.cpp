#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef long long ll;
int n;
char a[100005],b[100005];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	ll cnt1=0,cnt2=0,ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='1')
			cnt1++;
		if(a[i]=='0')
			cnt2++;
		if(a[i]=='0'&&b[i]=='0')
			cnt2--;
	}
	for(int i=1;i<=n;i++){
		if(a[i]=='0'&&b[i]=='0')
			ans+=cnt1;
		else if(a[i]=='1'&&b[i]=='0')
			ans+=cnt2;
	}
	cout<<ans<<endl;
	return 0;
}