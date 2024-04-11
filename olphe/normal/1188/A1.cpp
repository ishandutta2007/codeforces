#include "bits/stdc++.h"

using namespace std;

int N,M,K,L,R,H,W;
//long long int N,M,K,L,R,H,W;

//const long long int MOD=1000000007;
const long long int MOD=998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N;
	vector<vector<int>>edge(N);
	for(int i=1;i<N;i++){
		cin>>L>>R;
		L--;
		R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	for(int i=0;i<N;i++){
		if(edge[i].size()==2){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}