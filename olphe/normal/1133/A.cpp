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
	int a=0;
	a+=(s[0]-'0')*600;
	a+=(s[1]-'0')*60;
	a+=(s[3]-'0')*10;
	a+=(s[4]-'0')*1;
	int b=0;
	b+=(t[0]-'0')*600;
	b+=(t[1]-'0')*60;
	b+=(t[3]-'0')*10;
	b+=(t[4]-'0')*1;
	int c=(a+b)/2;
	cout<<c/600;
	c%=600;
	cout<<c/60;
	c%=60;
	cout<<":";
	cout<<c/10;
	c%=10;
	cout<<c<<endl;
}