#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,t;
	cin>>a>>b;t=__gcd(a,b);
	for(int i=1;i<t;i++){
		int s=sqrt(t*t-i*i);
		if(s*s==t*t-i*i){
			cout<<"YES\n0 0\n";
			cout<<s*a/t<<' '<<i*a/t<<'\n';
			int c1=-i*b/t,c2=s*b/t;
			if(c1==s*a/t||c2==i*a/t){
				c1*=-1;c2*=-1;
			}
			cout<<c1<<' '<<c2;return 0;
		}
	}
	cout<<"NO";
	return 0;
}