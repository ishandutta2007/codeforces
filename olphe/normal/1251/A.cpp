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
		string s;
		cin>>s;
		vector<int>v(26);
		int cnt=1;
		for(int i=1;i<s.size();i++){
			if(s[i]==s[i-1])cnt++;
			else {
				if(cnt&1)v[s[i-1]-'a']=1;
				cnt=1;
			}
		}
		if(cnt&1)v[s.back()-'a']=1;
		for(int i=0;i<26;i++)if(v[i])cout<<char('a'+i);
		cout<<endl;
	}
}