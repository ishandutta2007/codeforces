#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
	ll n;
	cin>>n;
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	n++;
	if(n&1){
		cout<<n<<endl;
	}else{
		cout<<n/2<<endl;
	}
	return 0;
}