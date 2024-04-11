#include<bits/stdc++.h>
using namespace std;
int main(){
	int a1,a2,b1,b2;
	cin>>a1>>b1>>a2>>b2;
	int ns,ms;
	ns=(a1+1+b1+1)*2;
	ms=(a2+1+b2+1)*2;
	int ans=ns+ms-(min(a1,a2)+2)*2;
	cout<<ans;
	return 0;
}