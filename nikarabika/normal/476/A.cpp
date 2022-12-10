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
	int n, m;
	cin>>n>>m;
	if(n%2==0){
		int mv=n/2;
		if(m>2*mv)
			cout<<-1<<endl;
		else
			cout<<mv+((((m-mv)%m)+m)%m)<<endl;
	}
	else{
		int mv=n/2;
		mv++;
		if(m>=2*mv)
			cout<<-1<<endl;
		else
			cout<<mv+((((m-mv)%m)+m)%m)<<endl;
	}
	return 0;
}