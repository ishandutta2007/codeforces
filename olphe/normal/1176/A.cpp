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
	while(N--){
		cin>>M;
		int ans=0;
		while(M>1){
			if(M%2==0){
				M/=2;
				ans++;
			}
			else if(M%3==0){
				M*=2;
				M/=3;
				ans++;
			}
			else if(M%5==0){
				M*=4;
				M/=5;
				ans++;
			}
			else{
				cout<<-1<<endl;
				break;
			}
		}
		if(M==1){
			cout<<ans<<endl;
		}
	}
}