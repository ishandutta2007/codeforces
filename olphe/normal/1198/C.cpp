#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

struct Edge{
	int to,index;
	Edge(const int t,const int i){
		to=t;
		index=i;
		return;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>K;
	vector<string>rets;
	vector<vector<int>>retv;
	while(K--){
		cin>>N>>M;
		vector<pair<int,int>>edge(M);
		vector<int>used(N*3);
		vector<int>mat;
		for(int i=0;i<M;i++){
			cin>>L>>R;
			L--;
			R--;
			edge[i]={R,L};
			if(!used[L]&&!used[R]){
				used[L]=used[R]=1;
				mat.push_back(i+1);
			}
		}
		if(mat.size()>=N){
			mat.resize(N);
			rets.push_back("Matching");
			retv.push_back(mat);
		}
		else{
			vector<int>ind;
			rets.push_back("IndSet");
			for(int i=0;i<N*3;i++){
				if(!used[i])ind.push_back(i+1);
			}
			ind.resize(N);
			retv.push_back(ind);
		}
	}
	for(int i=0;i<rets.size();i++){
		cout<<rets[i]<<endl;
		for(auto j:retv[i])cout<<j<<" ";
		cout<<endl;
	}
	return 0;
}