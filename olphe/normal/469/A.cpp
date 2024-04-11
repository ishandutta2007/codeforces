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
	vector<int>v(N+1);
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>K;
		v[K]=1;
	}
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>K;
		v[K]=1;
	}
	if(accumulate(v.begin(),v.end(),0)==N)cout<<"I become the guy."<<endl;
	else cout<<"Oh, my keyboard!"<<endl;
}