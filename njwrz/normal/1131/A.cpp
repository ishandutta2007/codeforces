#include<bits/stdc++.h>
using namespace std;
int main(){
	int n1,n2,m1,m2;
	cin>>n1>>m1>>n2>>m2;
	int ns,ms;
	ns=(n1+1+m1+1)*2;
	ms=(n2+1+m2+1)*2;
	int ans=ns+ms-(min(n1,n2)+2)*2;
	cout<<ans;
	return 0;
}