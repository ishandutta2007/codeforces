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
	for(auto&i:v)cin>>i;
	int ans=0;
	for(int i=0;i+1<N;i++){
		if(v[i]!=v[i+1]){
			int box=2;
			for(int j=1;i-j>=0&&i+j+1<N;j++){
				if(v[i-j]==v[i]&&v[i+j+1]==v[i+1])box+=2;
				else break;
			}
			ans=max(ans,box);
		}
	}
	cout<<ans<<endl;
}