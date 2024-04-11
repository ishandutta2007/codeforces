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
#define MAX 2000010
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;

void display(vector<ll> a){
	for(auto& f: a)
		cout<<f<<' ';
	cout<<endl;
}

void fx(ll lon, ll hin, ll& lo, ll& hi, vector<ll>& arr, multiset<ll>& all){
	while(hi<hin){
		++hi;
		all.insert(arr[hi]);
	}
	while(lo<lon){
		all.erase(all.find(arr[lo]));
		++lo;
	}
	while(lo>lon){
		--lo;
		all.insert(arr[lo]);
	}
	while(hi>hin){
		all.erase(all.find(arr[hi]));
		--hi;
	}
	
}

void deal(){
	ll n , w;
	cin>>n>>w;
	vector<ll> ans(w,0);
	vector<ll> add(w+1,0);
	fori(n){
		ll len;
		cin>>len;
		vector<ll> arr(len);
		fori(len)
			cin>>arr[i];
		multiset<ll> all;
		ll lo = 0, hi = -1;
		for(ll i =0; i<len; i++){
			ll lon , hin ;
			ll ind = w-len;
			ll val = -inf;
			if(ind > i)
				val  = max(val, (ll)0), lon = 0;
			else
				lon = i-ind;
			hin = i;
		//	cout<<"index "<<i<<" lo hi "<<lo<<" "<<hi<<" new: "<<lon<<" "<<hin<<endl; 
			fx(lon,hin,lo,hi,arr,all);
			val = max(val, (*all.rbegin()));
			ans[i]+=val;
		}
		lo = 0, hi = -1;
		all.clear();
		for(ll i = w-1; i>=max(w-len,len); i--){
			ll lon , hin;
			ll ind = w -len;
			ll val = 0;
//			cout<<"ind: "<<ind<<" i - ind: "<<i-ind<<endl;
			lon = i-ind;
			hin = len-1;
			fx(lon, hin, lo, hi, arr, all);
//			cout<<lo<<" "<<hi<<endl;
			val = max(val, (*all.rbegin()));
			ans[i]+=val;
		}
		lo = 0, hi = 0;
		fx(0, len-1, lo, hi, arr, all);
		if(len < w-len && (*all.rbegin() > 0)){
			add[len]+=*all.rbegin();
			add[w-len]-=*all.rbegin();
		}
	}
	for(ll i =1; i<=w; i++)
		add[i]+=add[i-1];
	fori(w)
		ans[i]+=add[i];
	fori(w)
		cout<<ans[i]<<' ';
	
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}


/*
1 6
4 1 -1 2 -1
*/