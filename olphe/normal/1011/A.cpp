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
	vector<int>v(26);
	for(auto i:s)v[i-'a']++;
	int cnt=-1000;
	for(int i=0;i<26;i++){
		if(v[i]&&i-cnt>=2&&K){
			M+=i+1;
			K--;
			cnt=i;
		}
	}
	if(K)cout<<-1<<endl;
	else cout<<M<<endl;
}