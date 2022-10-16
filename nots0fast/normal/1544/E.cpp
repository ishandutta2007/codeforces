#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision
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
#define ld long double
#define pb(a) push_back(a)
#define mt make_tuple
#define MAX (int)(pow(10,6) + 5)
// #define cout out
// #define cin in
ll inf = pow(10, 18) + 100;
ll INF = pow(10, 9);
ll modulo = 998244353;
double eps = 1e-10;

string sorted(vector<ll>& tot){
	string a = "";
	fori(26){
		forj(tot[i]){
			a+=('a' + i);
		}
	}
	return a;
}

ll getk(vector<ll>& tot, ll k){
	ll seen = 0;
	fori(26){
		if(tot[i]){
			++seen;
			if(seen == k){
				return i;
			}
		}
	}
	return -1;
}

string zigzag(vector<ll> tot){
	string ans = "";
	ll lz = getk(tot, 1);
	fori(2){
		ll wh = getk(tot, 1);
		tot[wh]--;
		ans+=wh + 'a';
	}
	{
		ll wh = getk(tot, 2);
		tot[wh]--;
		ans+=wh+'a';
	}
	while(1){
		ll wh = getk(tot, 1);
		if(wh != lz){
			return ans + sorted(tot);
		}
		tot[wh]--;
		ans+=wh+'a';
		if(getk(tot, 1) != lz){
			return ans + sorted(tot);
		}
		wh = getk(tot, 2);
		if(wh == -1){
			return "";
		}
		tot[wh]--;
		ans+=wh+'a';
	}
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		vector<ll> tot(26, 0);
		string a;
		cin>>a;
		for(auto& f : a){
			tot[f-'a']++;
		}
		ll lz = -1;
		fori(26){
			if(tot[i] == 1){
				lz = i;
				break;
			}
		}
		if(lz!=-1){
			string ans = "";
			ans+=('a' + lz);
			tot[lz]--;
			ans+=sorted(tot);
			cout<<ans<<'\n';
			continue;
		}
		lz = getk(tot, 1);
		if(tot[lz] <= 2 || tot[lz] == (ll)a.length()){
			cout<<sorted(tot)<<'\n';
			continue;
		}
		string ans = zigzag(tot);
		if(ans == ""){
			if(getk(tot, 3) != -1){
				ll lz1 = getk(tot, 1);
				ll lz2 = getk(tot, 2);
				ll lz3 = getk(tot, 3);
				ans += ('a' + lz1);
				ans += ('a' + lz2);
				tot[lz1]--;
				tot[lz2]--;
				while(tot[lz1]){
					ans+=('a' + lz1);
					tot[lz1]--;
				}
				ans += ('a' + lz3);
				tot[lz3]--;
				ans+=sorted(tot);
			}
			else{
				ll lz1 = getk(tot, 1);
				ll lz2 = getk(tot, 2);
				ans+=('a' +lz1);
				tot[lz1]--;
				while(tot[lz2]){
					ans+=('a' + lz2);
					tot[lz2]--;
				}
				while(tot[lz1]){
					ans+=('a'+lz1);
					tot[lz1]--;
				}
			}
		}
		cout<<ans<<'\n';
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	deal();
}