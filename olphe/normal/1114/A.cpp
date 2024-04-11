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

	int A,B,C;
	int g,p,b;
	cin>>A>>B>>C;
	cin>>g>>p>>b;
	if(A>g){
		cout<<"NO\n";
		return 0;
	}
	g-=A;
	if(B>g+p){
		cout<<"NO\n";
		return 0;
	}
	g+=p;
	g-=B;
	if(C>g+b){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
}