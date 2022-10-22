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
	string t="ACTG";
	int ans=MOD;
	for(int i=0;i+3<N;i++){
		int box=0;
		for(int j=0;j<4;j++){
			box+=min(abs(s[i+j]-t[j]),26-abs(s[i+j]-t[j]));
		}
		ans=min(ans,box);
	}
	cout<<ans<<endl;
}