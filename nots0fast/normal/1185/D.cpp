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
#define MAX (int)(pow(10,6) + 10)

vector<ll> arr;
map<ll,ll> lst;

bool check(vector<ll> all){
	ll d = all[1] - all[0];
	for(ll i = 2; i<all.size(); i++)
		if(all[i]- all[i-1] != d)
			return 0;
	return 1;
}

void deal(){	 // 1 printed one , 0 - meant message
	ll n;
	cin>>n;
	arr.resize(n);
	fori(n)
		cin>>arr[i], lst[arr[i]] = i;
	sort(arr.begin(), arr.end());
	ll dif = arr[1] -arr[0];
	ll sv = -1;
	for(ll i = 2; i<arr.size(); i++){
		if(arr[i] - arr[i-1] != dif){
			if(sv == -1)
				sv = i;
		}
	}
	vector<ll> ch({0,1,sv, sv-1});
	fori(ch.size()){
		vector<ll> temp = arr;
		temp.erase(temp.begin() + ch[i]);
		if(check(temp)){
			cout<<lst[arr[ch[i]]]+1;
			return;
		}
	}
	cout<<-1;
}

int main()  
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}