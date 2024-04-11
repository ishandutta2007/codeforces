#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N>>L>>R;
	vector<int>v(N);
	for(auto &i:v)cin>>i;
	for(int i=0;i<N;i++){
		bool flag=true;
		for(int j=1;j<=L&&i-j>=0;j++)flag&=v[i]<v[i-j];
		for(int j=1;j<=R&&i+j<N;j++)flag&=v[i]<v[i+j];
		if(flag){
			cout<<i+1<<endl;
			return 0;
		}
	}
	return 0;
}