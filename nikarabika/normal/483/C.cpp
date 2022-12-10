#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef short int si;

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;
	if(k==1){
		FOR(i, 1, n-1)
			cout<<i<<' ';
		cout<<n<<endl;
		return 0;
	}
	for(int i=0; i<k/2 && (i==0 || cout<<' '); i++)
		cout<<n-i<<' '<<i+1;
	if(k%2==0)
		for(int i=k/2+1; i<=n-k/2 && cout<<' '; i++)
			cout<<i;
	else
		for(int i=n-k/2; i>=k/2+1 && cout<<' '; i--)
			cout<<i;
	cout<<endl;
	return 0;
}