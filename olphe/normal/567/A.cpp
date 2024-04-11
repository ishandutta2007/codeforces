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
	vector<int>v(N);
	for(auto &i:v)cin>>i;
	for(int i=0;i<N;i++){
		int ans=MOD*2;
		if(i)ans=min(ans,v[i]-v[i-1]);
		if(i+1<N)ans=min(ans,v[i+1]-v[i]);
		cout<<ans<<" ";
		ans=max(v[i]-v[0],v.back()-v[i]);
		cout<<ans<<endl;
		
	}
}