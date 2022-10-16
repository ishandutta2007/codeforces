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
#define mt make_tuple
typedef long double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 18);
ll modulo = pow(10,9) + 7;


void deal(){
	ll n;
	cin>>n;
	vector<ll> a1(n), a2(n);
	fori(n){
		cin>>a1[i];
	}
	fori(n){
		cin>>a2[i];
	}
	
	set<ll> av;
	fori(n-1){
		av.insert(i);
	}
	av.insert(-1);
	
	vector<ll> bfs(1, n-1);
	vector<ll> dt(n, inf);
	vector<pair<ll,ll> > wh(n);
	dt[n-1] = 0;
	fori((ll)bfs.size()){
		ll hd = bfs[i];
		auto it = av.lower_bound(hd);
		--it;
	//	cout<<"we unlocked "<<hd<<endl;
		while(1){
		//	cout<<"*it is "<<*it<<" a1[hd] is "<<a1[hd]<<endl;
			if(*it < hd - a1[hd]){
				break;
			}
			ll ini = *it;
		//	cout<<"so initial is "<<ini<<endl;
			if(ini == -1){
				cout<<dt[hd]+1<<'\n';
				vector<ll> ans;
				ans.pb(0);
				while(hd != n-1){
					ans.pb(wh[hd].ff+1);
					hd = wh[hd].ss;
				}
				reverse(ans.begin(), ans.end());
				for(auto& el : ans){
					cout<<el<<' ';
				}
				return;
			}
			ll cur = ini + a2[ini];
		//	cout<<"but we go down by some so we are at "<<cur<<endl;
			if(dt[hd] + 1 < dt[cur]){
				dt[cur] = dt[hd]+1;
				wh[cur] = mp(ini, hd);
				bfs.pb(cur);
			}
			auto itn = it;
			++itn;
			av.erase(it);
			if(itn!=av.begin()){
				--itn;
				it = itn;
			}
		}
	}
	cout<<-1;
}


int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}