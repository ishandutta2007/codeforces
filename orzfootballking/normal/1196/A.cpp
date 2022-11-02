#include<bits/stdc++.h>
using namespace std;
int main() {
	long long x,n,y,z;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>x>>y>>z;
		x+=y;
		x+=z;
		cout<<x/2<<'\n';
	}
	return 0;
}