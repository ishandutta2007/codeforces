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
#define pb(a) push_back(a)
#define PI 2*acos(0)
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 2*pow(10,9)+10;
const ll inf =  pow(10,18);
ll modulo = 163577857;
#define MAX 100100

void cons(string& a, vector<ll>& cur){
	fori(26)
		cur[i] = 0;
	for(char f : a)
		cur[f-'a'] ++;
}
bool ch(string a, string b){ // a is sub of b
	ll ind = 0;
	for(auto f : b)
		if(ind<a.length() && a[ind] ==f)
			++ind;
	return ind == a.length();
}
void deal(){
	ll t;
	cin>>t;
	forl(t){
		string s,t,p;
		cin>>s>>t>>p;
		vector<ll> arr1(26), arr2(26);
		cons(s,arr1);
		cons(t, arr2);
		bool ok = 1;
		ok&=ch(s,t);
		fori(26)
			ok&=(arr1[i] <= arr2[i]);
		s+=p;
		cons(s, arr1);
		fori(26)
			ok&=(arr1[i] >= arr2[i]);
		if(ok)
			cout<<"YES\n";
		else	
			cout<<"NO\n";
	}
}
int main(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	deal();
}