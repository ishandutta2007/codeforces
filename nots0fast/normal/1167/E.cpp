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
#define MAX 2000100
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;
ll ls[MAX];
ll fir[MAX];
ll Mn[MAX];
map<ll,ll> all;
void deal(){
	fori(MAX)
		ls[i] = -1;
	fori(MAX)
		fir[i] = inf;
	ll n,x;
	cin>>n>>x;
	fori(n){
		int ed;
		cin>>ed;
		ls[ed] = i;
		fir[ed] = min(fir[ed], i);
	}
	ll a = 1, b = x;
	while(a<b){
		ll c = (a+b)/2;
		ll las = -1;
		bool gg = 1;
		for(int i=c; i<MAX; i++){
			if(ls[i] == -1)
				continue;
			if(fir[i] < las){
				gg = 0;
				break;
			}
			las = ls[i];
		}
		if(gg)
			b=c;
		else
			a=c+1;
	}
	// after (>=) a works
	ll sum = x+2-a;
	if(a==1)
		--sum;
//	cout<<"initial sum : "<<sum<<endl;
	ll ct = a;
	ll track = -1;
	Mn[MAX-1] = inf;
	for(int i=MAX-2; i>-1; i--)
		Mn[i] = min(fir[i], Mn[i+1]);
	for(ll i=1; i<x; i++){ // consider for i
		while(Mn[ct] <= ls[i])
			++ct;
//		cout<<"the new counter: "<<fir[i]<<" "<<track<<ct<<endl;
		if(fir[i] < track)
			break;
		track = max(track, ls[i]);
		if(ct==i)
			++ct;
//		cout<<"so we addin in case if it is not last "<<x+2-ct<<endl;
		if(ct!=i+1)
			sum+=x+2-ct;
		else
			sum+=x+1-ct;
	}
	cout<<sum;
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





/* 
1
7 
...O...
..O.O..
.O.O.O.
O.O.O.O
.....O.
.......
.......




*/