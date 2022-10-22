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
	int a=(s[0]-t[0])*600+(s[1]-t[1])*60+(s[3]-t[3])*10+(s[4]-t[4]);
	a+=1440*10000;
	a%=1440;
	cout<<a/600;
	a%=600;
	cout<<a/60;
	a%=60;
	cout<<":";
	cout<<a/10;
	a%=10;
	cout<<a<<endl;
}