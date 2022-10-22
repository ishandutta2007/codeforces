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
	vector<int>v(2);
	v[1]=1;
	while(v.back()<1000000000){
		v.push_back(v[v.size()-2]+v.back());
	}
	vector<int>ans;
	while(ans.size()<3){
		int nx=0;
		for(auto i:v){
			if(N>=i)nx=i;
		}
		ans.push_back(nx);
		N-=nx;
	}
	if(N){
		cout<<"I'm too stupid to solve this problem\n";
	}
	else{
		cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
	}
}