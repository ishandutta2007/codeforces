#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define double long double
#define MAX 400010
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;


void deal(){
	string a;
	cin>>a;
	string  b = "";
	vector< int > all;
	int las = -1;
	fori(a.length()){
		if(a[i] == 'a')
			las = i;
		else
			b+=a[i], all.pb(i);
	}
	if( ((int)all.size()&1) || (all.size() && all[all.size()/2 ] < las) ){
		cout<<":(";
		return;
	}
		fori(b.length()/2)
			if(b[i] != b[b.length()/2+i]){
				cout<<":(";
				return;
			}
	string z = "";
	int cnt = 0, i = 0;
	while(i<=las || cnt<(int)all.size()/2){
		if(a[i] != 'a')
			cnt++;
		z+=a[i];
		++i;
	}
	cout<<z;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}