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
	vector<int>ans;
	for(int i=1;i<=N;i++){
		cin>>M;
		L=K;
		for(int j=0;j<M;j++){
			cin>>R;
			L=min(L,R);
		}
		if(L<K)ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i<<" ";
	cout<<endl;
}