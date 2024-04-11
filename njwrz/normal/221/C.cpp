#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
	int n,t=0;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],b[i]=a[i];
	sort(b,b+n);
	for(int i=0;i<n;i++)t+=(a[i]!=b[i]);
	if(t<=2)cout<<"YES";else cout<<"NO";
	return 0;
}