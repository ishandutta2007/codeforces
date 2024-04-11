#include<bits/stdc++.h>

using namespace std;

int n;
char a[1000005],b[1000005];

int main(){
	cin>>n>>(a+1)>>(b+1);
	int ans=0;
	for(int i=1;i<=n-1;i++)
		if(a[i]!=b[i]&&a[i+1]!=b[i+1]&&a[i]!=a[i+1])
			a[i]=b[i],a[i+1]=b[i+1],ans++;
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i])
			a[i]=b[i],ans++;
	cout<<ans<<endl;
	return 0;
}