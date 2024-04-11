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
#define MAX (int)(pow(10,6)+10)
#define pb(a) push_back(a)
#define ld long double
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;


bool check(string a, string ch){
	ll n = a.length() - 1;
	fori(n){
		if(a[i] == ch[0] && a[i+1] == ch[1])
			return false;
	}
	return true;
}

void deal(){
	ll n;
	string a,b;
	cin>>n>>a>>b;
	vector<ll> arr({0,1,2});
	do{
		char all[3];
		fori(3)
			all[i] = ('a' + arr[i]);
		
		string a1 = "";
		forj(3)
			fori(n)
				a1+=all[j];
		
		string a2 = "";
		fori(n)
			forj(2)
				a2+=all[j];
		fori(n)
			a2+=all[2];
		
		string a3 = "";
		fori(n)
			a3+=all[0];
		fori(n)
			a3+=all[1], a3+=all[2];
		
		string a4 = "";
		fori(n)
			forj(3)
				a4+=all[j];
		vector<string> todo ({a1,a2,a3,a4});
		for(auto el : todo){
			if(check(el, a) && check(el,b)){
				cout<<"YES\n"<<el;
				return;
			}
		}
		
	}while(next_permutation(arr.begin(), arr.end()));
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}