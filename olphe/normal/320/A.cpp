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
	reverse(s.begin(),s.end());
	int cnt=0;
	for(auto i:s){
		if(i=='4'){
			cnt++;
		}
		else if(i=='1'){
			if(cnt>2){
				cout<<"NO\n";
				return 0;
			}
			cnt=0;
		}
		else{
			cout<<"NO\n";
			return 0;
		}
	}
	if(cnt){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
	}
}