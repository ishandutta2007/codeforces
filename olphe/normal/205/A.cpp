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
	int ans=0;
	vector<int>v(N);
	int cnt=MOD;
	for(auto &i:v){
		cin>>i;
		cnt=min(cnt,i);
	}
	for(int i=0;i<N;i++){
		if(cnt==v[i]){
			if(ans){
				cout<<"Still Rozdil\n";
				return 0;
			}
			else{
				ans=i+1;
			}
		}
	}
	cout<<ans<<endl;
}