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
	vector<int>o;
	vector<int>e;
	for(int i=0;i<N;i++){
		cin>>K;
		if(K&1)o.push_back(K);
		else e.push_back(K);
	}
	sort(o.begin(),o.end());
	sort(e.begin(),e.end());
	int ans=0;
	L=o.size(),R=e.size();
	if(abs(L-R)<=1){
		cout<<0<<endl;
		return 0;
	}
	if(o.size()>e.size()){
		for(int i=0;i<o.size()-e.size()-1;i++){
			ans+=o[i];
		}
	}
	else{
		for(int i=0;i<e.size()-o.size()-1;i++){
			ans+=e[i];
		}
	}
	cout<<ans<<endl;
}