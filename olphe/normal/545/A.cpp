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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N;
	vector<vector<int>>v(N,vector<int>(N));
	for(auto &i:v)for(auto &j:i)cin>>j;
	vector<int>ans(N,1);
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(v[i][j]==3)ans[i]=ans[j]=0;
			if(v[i][j]==1)ans[i]=0;
			if(v[i][j]==2)ans[j]=0;
		}
	}
	vector<int>ret;
	for(int i=0;i<N;i++){
		if(ans[i])ret.push_back(i+1);
	}
	cout<<ret.size()<<endl;
	for(auto i:ret)cout<<i<<" ";
	cout<<endl;
}