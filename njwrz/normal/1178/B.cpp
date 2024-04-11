#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int main() {
	long long n=0;
	while(cin>>a[n++]);
	long long t=0;
	for(long long i=0;i<n-1;i++){
		if(a[i]=='v'&&a[i+1]=='v'){
			t++;
		}
	}
	long long ans=0,p=0;
	for(long long i=0;i<n-1;i++){
		if(a[i]=='o'){
			ans+=(t-p)*p;
		}else if(a[i]=='v'&&a[i+1]=='v'){
			p++;
		}
	}
	cout<<ans;
	return 0;
}