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
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  2*pow(10,9);
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,5) + 10)

string func(string a, string b){
	if ( a.length () > b.length() )
	 	return b;
 	if ( a.length () < b.length() )
         return a;
    return min(a,b);
     
}


string add(string a, string b){
	ll ql = 0;
	if(a.length() < b.length())
		swap(a,b);
	string bif = "";
	for(ll i = 0; i<((ll)a.length() - (ll)b.length()); i++)
		bif+='0';
	b = bif + b;
	for(ll i = b.length()-1; i>-1; i--){
		ll cur = (b[i]-'0') + (a[i]-'0') + ql;
		ql = cur/10;
		a[i] = (cur%10)+'0';
	}
	if(ql)
		a = "1" + a;
	return a;
}

void deal(){
	ll n;
	cin>>n;
	string a;
	cin>>a;
	ll mn = inf;
	for(ll i = 1; i<n; i++)
		if(a[i]!='0')
			mn = min(mn, max(i, n-i));
	string res = "";
	for(ll i = 1; i<n; i++)
		if(a[i]!='0' && max(i,n-i)==mn){
			string lf = "", rg = "";
			fork(i)
				lf += a[k];
			for(ll k = i; k<n; k++)
				rg += a[k];
			if(res == "")
				res = add(lf, rg);
			else
				res = func(res, add(lf,rg));
		}
	cout<<res;
}

int main()  
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}