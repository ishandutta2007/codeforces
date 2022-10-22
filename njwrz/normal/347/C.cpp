#include <bits/stdc++.h>
using namespace std;
int main(){
	int d,m,n,x;
	cin>>n;
	cin>>d;m=d;
	for(int i=1;i<n;i++){
		cin>>x;
		d=__gcd(d,x);
		m=max(m,x);
	}
	int ans=m/d-n;
	if(ans&1){
		cout<<"Alice";
	}else cout<<"Bob";
	return 0;
}