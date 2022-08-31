#include<bits/stdc++.h>

using namespace std;

int n,s;
int a[200005];

int main(){
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int x=a[(n+1)/2];
	long long ans=0;
	if(s==x)
		cout<<0<<endl;
	else if(s>x){
		ans+=s-x;
		for(int j=(n+3)/2;j<=n;j++)
			if(a[j]<s)
				ans+=s-a[j];
		cout<<ans<<endl;
	}
	else{
		ans+=x-s;
		for(int j=1;j<=(n-1)/2;j++)
			if(a[j]>s)
				ans+=a[j]-s;
		cout<<ans<<endl;
	}
	return 0;
}