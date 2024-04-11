#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
 
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
typedef long double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 18);
const ll modulo = pow(10,9) + 7;

void brute(){
	ll n ;
	cin>>n;
	ll bt = 0;
	fori(n){
		ll ed;
		cin>>ed;
		if(ed){
			bt|=(1<<(n-1-i));
		}
	}
	set<ll> all;
	all.insert(bt);
	vector<ll> bfs;
	bfs.pb(bt);
	vector<ll> wh(1<<n, -1);
	wh[bt] = bt;
	fori((ll)bfs.size()){
		ll cr = bfs[i];
		forj(n-2){
			ll nw = cr;
			ll a = 0;
			a += (((1<<j)&cr) != 0);
			a += (((1<<(j+1))&cr) != 0);
			a += (((1<<(j+2))&cr) != 0);
			if(a % 2 == 1){
				nw |= (1<<j);
				nw |= (1<<(j+1));
				nw |= (1<<(j+2));
			}
			else{
				if(nw & (1<<j)){
					nw ^= (1<<j);
				}
				if(nw & (1<<(j+1))){
					nw ^= (1<<(j+1));
				}
				if(nw & (1<<(j+2))){
					nw ^= (1<<(j+2));
				}
			}
			if(all.find(nw) == all.end()){
				all.insert(nw);
				bfs.pb(nw);
				wh[nw] = cr;
			}
		}
	}
	if(wh[0]!=-1){
		cout<<"0 is visited "<<endl;
		vector<ll> all;
		ll cr = 0;
		while(wh[cr] != cr){
			all.pb(cr);
			cr = wh[cr];
		}
		all.pb(cr);
		reverse(all.begin(), all.end());
		cout<<"the path "<<endl;
		for(auto& el: all){
			cout<<bitset<20>(el)<<endl;
		}
	}
	else{
		cout<<"0 is not visited"<<endl;
	}
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		vector<ll> arr(n);
		fori(n){
			cin>>arr[i];
		}
		vector<pair<ll,ll> > all;
		{
			ll st = 0;
			while(st < n){
				if(arr[st] == 0){
					++st;
					continue;
				}
				ll nd = st;
				while(nd < n && arr[nd] == 1){
					++nd;
				}
				all.pb(mp(st, nd-1));
				st = nd;
			}
		}
		bool bad = 0;
		vector<ll> op;
		for(ll i = 0; i<(ll)all.size(); i++){
			ll nd = all[i].ss, st = all[i].ff;
			if(nd < st){
				continue;
			}
			if((nd-st + 1) % 2 == 0){
				if(st != 0){
					for(ll j = st-1; j<nd; j+=2){
						op.pb(j);
					}
				}
				else if(nd!=n-1){
					for(ll j = nd-1; j>=st; j-=2){
						op.pb(j);
					}
				}
				else{
					bad = 1;
					break;
				}
			}
			else{
				if(i!=(ll)all.size() -1){
					if((all[i+1].ff - nd) % 2 == 0){
						for(ll j = nd; j<all[i+1].ff; j+=2){
							op.pb(j);
						}
						nd = all[i+1].ff - 3;
						all[i+1].ff++;
						if(nd >= st){
							for(ll j = nd + 1; j >= st; j-=2){
								op.pb(j);
							}
						}
					}
					else{
						for(ll j = nd; j+1<all[i+1].ff; j+=2){
							op.pb(j);
						}
						all[i+1].ff = st;
					}
				}
				else{
					bad = 1;
					break;
				}
			}
		}
		if(bad){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
			cout<<op.size()<<'\n';
			for(auto& el : op){
				cout<<el+1<<' ';
			}
			cout<<'\n';
		}
	}
}
 
int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}