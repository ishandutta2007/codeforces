#include<iostream>

using namespace std;

int n,p,q;
int a[100005],s[100005];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	cin>>p>>q;
	int t,ans,maxa=0;
	for(int i=1;i<=n;i++){
		if(i<=p)
			t=s[q-i]-s[p-i];
		else if(i<=q)
			t=s[q-i]+s[n]-s[n+p-i];
		else
			t=s[n+q-i]-s[n+p-i];
		if(t>maxa){
			maxa=t;
			ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}