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
const ll inf =  pow(10,18);
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,6) + 10)



void deal(){
	ll n, k;
	cin>>n>>k;
	vector<ll> arr1(n), arr2(n);
	fori(n)
		cin>>arr1[i], -- arr1[i];
	fori(n)
		cin>>arr2[i], -- arr2[i];
	reverse(arr1.begin(), arr1.end());
	reverse(arr2.begin(), arr2.end());
	char lst = 'z';
	ll last  =  0;
	map<ll,ll> all;
	ll not_equal = 0;
	string answer;
	fori(n)
		answer+=" ";
	fori(n){
		all[arr1[i]]++;
		if(all[arr1[i]]!=2)
			++not_equal;
		else
			--not_equal;
		all[arr2[i]]++;
		if(all[arr2[i]]!=2)
			++not_equal;
		else
			--not_equal;
		if(not_equal == 0){
			for(ll j = last; j<=i; j++)
				answer[arr1[j]] = lst;
			if(lst!='a')
				lst--;
			last = i + 1;
		}
	}
	char need = 'z';
	need-=(k-1);
	if(answer[arr1[n-1]]<=need)
		cout<<"YES\n"<<answer;
	else
		cout<<"NO";
}

void test(){
	char f = 'z';
	forj(26){
	cout<<f<<endl;
	f--;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
//	test();
	deal();
}