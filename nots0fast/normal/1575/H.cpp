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
typedef  double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 18);
ll modulo = pow(10,9) + 7;

void deal(){
	ll n, m;
	cin>>n>>m;
	string a1, a2;
	cin>>a1>>a2;
	vector<vector<ll> > kmp(m, vector<ll>(2, 0));
	fori(m){
		forj(2){
			// we had a prefix of length i we took char j
			string cur = a2.substr(0, i);
			cur+=(j+'0');
			ll curlen = cur.length();
			for(ll len = i+1; len; len--){
				bool gg = 1;
				for(ll k = 0; k<len; k++){
					if(a2[k] != cur[curlen-len+k]){
						gg = 0;
						break;
					}
				}
				if(gg){
					kmp[i][j] = len;
					break;
				}
			}
		}
	}
	ll speclen = 0;
	{
		string cur = a2.substr(0, m);
		ll curlen = cur.length();
		for(ll len = m-1; len; len--){
			bool gg = 1;
			for(ll k = 0; k<len; k++){
				if(a2[k] != cur[curlen-len+k]){
					gg = 0;
					break;
				}
			}
			if(gg){
				speclen = len;
				break;
			}
		}
	}
	vector<vector<ll> > dp(m, vector<ll>(n-m+2, inf));
	// i = longest prefix of equal length, occurence count
	dp[0][0] = 0;
	fori(n){
		vector<vector<ll> > dpn(m+1, vector<ll>(n-m+2, inf));
	//	cout<<"index  "<<i+1<<endl;
		forj(m){
			fork(n-m+2){
				if(dp[j][k] == inf){
					continue;
				}
				forl(2){
					ll add = 0;
					if(l != a1[i] - '0'){
						++add;
					}
					ll i1 = kmp[j][l];
					ll i2 = k;
					if(i1 == m){
						i1 = speclen;
						i2 = k+1;
					}
			//		cout<<"we can transition from "<<j<<" "<<k<<" to "<<i1<<" "<<i2<<" with cost "<<dp[j][k]+add<<endl;
					if(dp[j][k] + add < dpn[i1][i2]){
						dpn[i1][i2] = dp[j][k] + add;
					}
				}
			}
		}
		dp = dpn;
		/*
		fori((ll)dp.size()){
			forj((ll)dp[i].size()){
				if(dp[i][j]!=inf){
					cout<<"so "<<i<<" length prefix and "<<j<<" occurence is "<<endl;
					cout<<dp[i][j]<<" now "<<endl;
				}
			}
		}
		*/
	}
	forj(n-m+2){
		ll mn = inf;
		fori(m){
			mn = min(mn, dp[i][j]);
		}
		if(mn == inf){
			mn = -1;
		}
		cout<<mn<<' ';
	}
}
 

int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}