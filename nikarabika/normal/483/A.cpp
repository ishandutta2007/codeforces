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
ull l, r;
	cin>>l>>r;
	
	if(l==1){
		if(r<=3)
			cout<<-1<<endl;
		else
			cout<<"2 3 4"<<endl;
		return 0;
	}
	if(r-l<=1 || (r-l==2 && l%2==1)){
		cout<<-1<<endl;
		return 0;
	}
	if(l%2==0)
		cout<<l<<' '<<l+1<<' '<<l+2<<endl;
	else
		cout<<l+1<<' '<<l+2<<' '<<l+3<<endl;
	return 0;
}