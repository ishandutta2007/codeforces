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
	
	char a;
	cin>>a;
	map<char,char>l;
	map<char,char>r;
	string s="qwertyuiop";
	string t="asdfghjkl;";
	string u="zxcvbnm,./";
	for(int i=1;i<s.size();i++){
		r[s[i]]=s[i-1];
	}
	for(int i=1;i<t.size();i++){
		r[t[i]]=t[i-1];
	}
	for(int i=1;i<u.size();i++){
		r[u[i]]=u[i-1];
	}
	for(int i=1;i<s.size();i++){
		l[s[i-1]]=s[i];
	}
	for(int i=1;i<t.size();i++){
		l[t[i-1]]=t[i];
	}
	for(int i=1;i<u.size();i++){
		l[u[i-1]]=u[i];
	}
	string v;
	cin>>v;
	bool flag=true;
	if(a=='R')for(auto i:v)cout<<r[i];
	else for(auto i:v)cout<<l[i];
	cout<<endl;
}