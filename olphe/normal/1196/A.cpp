#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
long long int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
//constexpr int MOD=1000000007;
constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>K;
	while(K--){
		vector<long long int>v(3);
		for(auto &i:v)cin>>i;
		sort(v.begin(),v.end());
		cout<<accumulate(v.begin(),v.end(),0LL)/2<<endl;
	}
	return 0;
}