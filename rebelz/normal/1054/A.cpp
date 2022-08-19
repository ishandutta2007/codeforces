#include<bits/stdc++.h>

using namespace std;

int x,y,z,t1,t2,t3;

int main(){
	cin>>x>>y>>z>>t1>>t2>>t3;
	if((fabs(z-x)+fabs(x-y))*t2+3*t3<=fabs(x-y)*t1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}