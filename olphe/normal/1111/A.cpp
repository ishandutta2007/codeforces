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
	
	string s,t;
	cin>>s>>t;
	map<char,int>mp;
	mp['a']=1;
	mp['i']=1;
	mp['u']=1;
	mp['e']=1;
	mp['o']=1;
	if(s.size()!=t.size()){
		cout<<"No\n";
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(mp[s[i]]!=mp[t[i]]){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
}