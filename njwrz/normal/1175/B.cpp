#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	long long t=1,ans=0,n,i,s,q=0;
	string x;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x;
		if(x=="for"){
			cin>>s;
			if(t<=4294967295)t*=s,a[q++]=s;else a[q++]=1;
		}else if(x=="add"){
			ans+=t;
		}else{
			t/=a[--q];
		}
		if(ans>4294967295){
			cout<<"OVERFLOW!!!";return 0;
		}
	}
	cout<<ans;
	return 0;
}