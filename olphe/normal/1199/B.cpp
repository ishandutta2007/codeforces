#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long double a,b;
	cin>>a>>b;
	long double c=b*b-a*a;
	c/=2*a;
	cout<<setprecision(15)<<c<<endl;
	return 0;
}