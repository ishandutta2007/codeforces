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
	vector<int>v;
	v.push_back(-1);
	cin>>s;
	map<char,int>mp;
	string box="AIUEOY";
	for(auto i:box)mp[i]=1;
	for(int i=0;i<s.size();i++){
		if(mp[s[i]])v.push_back(i);
	}
	v.push_back(s.size());
	int ans=0;
	for(int i=1;i<v.size();i++){
		ans=max(ans,v[i]-v[i-1]);
	}
	cout<<ans<<endl;
}