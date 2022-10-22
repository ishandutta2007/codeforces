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
	string s;
	cin>>s;
	vector<int>v(1);
	for(auto i:s){
		if(i=='R')M++;
		else M--;
		v.push_back(M);
	}
	int ans=0;
	for(int i=2;i<v.size();i++){
		if(v[i-2]<0&&v[i]>0)ans++;
		if(v[i-2]>0&&v[i]<0)ans++;
	}
	cout<<ans<<endl;
}