#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int cnt=0;
		while(n){
			n&=(n-1);
			cnt++;
		}
		cout<<(1ll<<cnt)<<endl;
	}
	return 0;
}