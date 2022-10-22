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
	
	string s;
	cin>>s;
	vector<int>used(26);
	vector<vector<long long int>>box(26,vector<long long int>(26));
	for(auto i:s){
		for(int j=0;j<26;j++){
			box[j][i-'a']+=used[j];
		}
		used[i-'a']++;
	}
	long long int ans=*max_element(used.begin(),used.end());
	for(auto i:box){
		ans=max(ans,*max_element(i.begin(),i.end()));
	}
	cout<<ans<<endl;
}