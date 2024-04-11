/*
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
*/

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
#define lll __int128
#define pb(a) push_back(a)
#define mt make_tuple
typedef long double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 18);
ll modulo = pow(10,9) + 7;

bool J(string& a, string& b){
	ll mn = min(a.length(), b.length());
	fori(mn){
		if(a[i]!=b[i]){
			if(i%2 == 0){
				return a[i] < b[i];
			}
			else{
				return a[i] > b[i];
			}
		}
	}
	return a.length() < b.length();
}

void deal(){
	ll n, m;
	cin>>n>>m;
	vector<string> arr;
	map<string, ll> num;
	fori(n){
		string a;
		cin>>a;
		num[a] = i+1;
		arr.pb(a);
	}
	sort(arr.begin(), arr.end(), J);
	for(auto& el : arr){
		cout<<num[el]<<' ';
	}
}
 

int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}