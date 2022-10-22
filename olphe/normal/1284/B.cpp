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
	vector<vector<int>>v(N);
	for(int i=0;i<N;i++){
		cin>>M;
		v[i].resize(M);
		for(auto &j:v[i])cin>>j;
	}
	vector<int>up(N);
	for(int i=0;i<N;i++){
		for(int j=1;j<v[i].size();j++){
			up[i]|=v[i][j]>v[i][j-1];
		}
	}
	long long int ans=N*N;
	vector<int>l;
	for(int i=0;i<N;i++){
		if(up[i])continue;
		l.push_back(v[i][0]);
	}
	sort(l.begin(),l.end());
	for(int i=0;i<N;i++){
		if(up[i])continue;
		ans-=upper_bound(l.begin(),l.end(),v[i].back())-l.begin();
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
}