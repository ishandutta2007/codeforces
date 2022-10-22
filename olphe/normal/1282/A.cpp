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
	
	cin>>K;
	while(K--){
		cin>>L>>R>>H>>W;
		if(L>R)swap(L,R);
		N=H-W;
		M=H+W;
		if(N<L){
			if(M<=L){
				cout<<R-L<<endl;
			}
			else if(M<=R){
				cout<<R-M<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
		else{
			if(N>=R){
				cout<<R-L<<endl;
			}
			else if(N>=L){
				if(M<=R){
					cout<<R-L-(M-N)<<endl;
				}
				else {
					cout<<N-L<<endl;
				}
			}
		}
	}
}