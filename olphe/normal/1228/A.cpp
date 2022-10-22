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

	cin>>L>>R;
	for(int i=L;i<=R;i++){
		int box=i;
		set<int>s;
		bool flag=true;
		while(box){
			if(s.find(box%10)!=s.end()){
				flag=false;
				break;
			}
			s.insert(box%10);
			box/=10;
		}
		if(flag){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}