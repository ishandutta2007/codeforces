#include "bits/stdc++.h"

using namespace std;

int N,M,K,L,R,H,W;
//long long int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N;
	vector<int>v(N);
	for(auto &i:v)cin>>i;
	vector<int>last(N);
	cin>>K;
	vector<int>box(K);
	for(int i=0;i<K;i++){
		cin>>M;
		if(M==1){
			cin>>L>>R;
			L--;
			v[L]=R;
			last[L]=i;
		}
		else{
			cin>>R;
			box[i]=R;
		}
	}
	for(int i=K-2;i>=0;i--)box[i]=max(box[i],box[i+1]);
	//for(auto i:box)cout<<i<<" ";
	//cout<<endl;
	for(int i=0;i<N;i++){
		//cout<<last[i]<<endl;
		cout<<max(v[i],box[last[i]])<<" ";
		//cout<<v[i]<<" "<<last[i]<<endl;
	}
	cout<<endl;
	return 0;
}