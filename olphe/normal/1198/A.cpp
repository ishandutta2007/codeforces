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
	
	cin>>N>>K;
	K*=8;
	K/=N;
	if(K>=30){
		cout<<0<<endl;
		return 0;
	}
	vector<int>v(N);
	map<int,int>num;
	for(auto &i:v){
		cin>>i;
		num[i]++;
	}
	map<int,int>m;
	vector<int>box;
	m[-MOD]=0;
	box.push_back(-MOD);
	M=1;
	for(auto i:num){
		m[i.first]=M++;
		box.push_back(i.first);
	}
	int ans=N;
	vector<int>sum(M);
	for(int i=1;i<M;i++){
		sum[i]=num[box[i]];
		sum[i]+=sum[i-1];
	}
	L=0,R=1;
	while(L+1<M){
		while(R+1<M&&R+1-(L+1)<(1<<K))R++;
		ans=min(ans,N-sum[R]+sum[L]);
		//cout<<L<<" "<<R<<endl;
		L++;
	}
	cout<<ans<<endl;
	return 0;
}