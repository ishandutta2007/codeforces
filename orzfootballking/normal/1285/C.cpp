#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	ll s;
	cin>>s;
	ll t=sqrt(s);
	for(ll i=t;i>=1;i--){
		if(s%i==0&&gcd(s/i,i)==1){
			cout<<i<<' '<<s/i;return 0;
		}
	}
	return 0;
}