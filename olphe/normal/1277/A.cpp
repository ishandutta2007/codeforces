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
	vector<string>t;
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			t.push_back(string(i,char('0'+j)));
		}
	}
	while(K--){
		string s;
		cin>>s;
		int ans=0;
		for(auto i:t){
			if(i.size()==s.size()){
				if(s>=i)ans++;
			}
			if(i.size()<s.size()){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}