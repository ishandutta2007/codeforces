#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
long long int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
constexpr  int MOD=1000000007;
//constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

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

long long int gcd(long long int a,long long int b){
	while(b){
		a%=b;
		swap(a,b);
	}
	return a;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N;
	vector<long long int>v(N);
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
	vector<vector<int>>edge(N);
	for(int i=1;i<N;i++){
		cin>>L>>R;
		L--;
		R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	vector<int>depth(N,MOD);
	vector<int>parent(N,-1);
	Calculate_Depth(edge,depth,0);
	vector<vector<pair<long long int,int>>>tapi(18,vector<pair<long long int,int>>(N,{-1,1}));
	for(int i=1;i<N;i++){
		for(auto j:edge[i]){
			if(depth[j]>depth[i])continue;
			parent[i]=j;
			tapi[0][i]={gcd(v[i],v[j]),j};
		}
	}
	for(int i=1;i<18;i++){
		for(int j=0;j<N;j++){
			if(tapi[i-1][j].first==-1)continue;
			tapi[i][j]={gcd(tapi[i-1][j].first,tapi[i-1][tapi[i-1][j].second].first),tapi[i-1][tapi[i-1][j].second].second};
		}
	}
	
	long long int ans=0;
	for(int i=0;i<N;i++){
		long long int num=v[i];
		int node=i;
		while(node!=-1){
			ans+=(num%MOD)*depth[node];
			ans%=MOD;
			for(int j=17;j>=0;j--){
				if(tapi[j][node].second!=-1&&gcd(num,tapi[j][node].first)==num){
					node=tapi[j][node].second;
				}
			}
			ans-=((num%MOD)*(depth[node]-1))%MOD;
			ans+=MOD;
			ans%=MOD;
			node=parent[node];
			if(node!=-1){
				num=gcd(num,v[node]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}