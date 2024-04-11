#include"bits/stdc++.h"
#include "chrono"
using namespace std;
typedef long long ll;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int a,b,n;
		scanf("%lld%lld%lld",&a,&b,&n);
		long long int cn=0;
		while(max(a,b)<=n){
			if(a<b)swap(a,b);
			//a>b
			b+=a;
			cn++;
		}
		cout<<cn<<endl;
	}
	return 0;
}