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
	
	cin>>N>>M;
	vector<long long int>by(N+1,1);
	for(int i=1;i<=N;i++){
		by[i]=by[i-1]*i;
		by[i]%=M;
	}
	long long int ans=0;
	for(int i=1;i<=N;i++){
		ans+=(N-i+1)*(N-i+1)%M*by[i]%M*by[N-i]%M;
	}
	cout<<ans%M<<endl;
}