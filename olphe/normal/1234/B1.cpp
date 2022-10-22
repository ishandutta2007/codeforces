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
	
	cin>>N>>K;
	vector<int>v;
	for(int i=0;i<N;i++){
		cin>>M;
		bool flag=true;
		for(auto j:v){
			if(j==M)flag=false;
		}
		if(flag){
			v.insert(v.begin(),M);
			if(v.size()>K)v.resize(K);
		}
	}
	cout<<v.size()<<endl;
	for(auto i:v)cout<<i<<" ";
	cout<<endl;
}