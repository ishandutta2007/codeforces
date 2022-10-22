#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,ans=0,a=1,b=1,c;
	cin>>n;
	while(a+b<=n){
		c=a+b;
		a=b;b=c;ans++;
	}
	cout<<ans;
	return 0;
}