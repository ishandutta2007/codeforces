#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

void Calculate_Depth(vector<vector<int>>&edge, vector<int>&depth, int stnode) {
	depth[stnode] = 0;
	queue<int>Q;
	Q.push(stnode);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (depth[i] > depth[cn] + 1) {
				depth[i] = depth[cn] + 1;
				Q.push(i);
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N>>M>>K;
	vector<int>w(K);
	for(auto &i:w)cin>>i;
	vector<vector<int>>edge(N);
	for(int i=0;i<M;i++){
		cin>>L>>R;
		L--,R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	vector<int>depthF(N,MOD);
	vector<int>depthL(N,MOD);
	Calculate_Depth(edge,depthF,0);
	Calculate_Depth(edge,depthL,N-1);
	vector<pair<int,int>>box;
	for(auto i:w){
		i--;
		box.push_back({depthF[i],depthL[i]});
	}
	int ans=0;
	sort(box.begin(),box.end());
	for(int i=1;i<box.size();i++){
		if(box[i].first==box[i-1].first){
			cout<<depthF.back()<<endl;
			return 0;
		}
		if(box[i].second>box[i-1].second){
			cout<<depthF.back()<<endl;
			return 0;
		}
		ans=max(ans,box[i-1].first+box[i].second+1);
	}
	cout<<ans<<endl;
}