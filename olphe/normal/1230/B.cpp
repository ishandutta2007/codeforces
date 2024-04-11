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
	
	cin>>N>>K;
	string s;
	cin>>s;
	if(N==1){
		if(K==1)cout<<0<<endl;
		else cout<<s<<endl;
		return 0;
	}
	if(s[0]!='1'&&K){
		K--;
		s[0]='1';
	}
	for(int i=1;i<s.size();i++){
		if(s[i]!='0'&&K){
			K--;
			s[i]='0';
		}
	}
	cout<<s<<endl;
}