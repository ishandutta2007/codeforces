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
const ll modulo = pow(10,9) + 7;

#define ch 800
#define MAX 200'010
int mods[ch][ch];
int dp[MAX];
int when[MAX];

void deal(){
	int n, m;
	cin>>n>>m;
	vector<pair<int,int> > arr(n);
	fori(n){
		cin>>arr[i].ff>>arr[i].ss;
	}
	for(int i = 1; i<=m; i++){
		dp[i]+=dp[i-1];
//		cout<<"dp is "<<dp[i]<<endl;
		int op, k;
		cin>>op>>k;
		--k;
		int xi = arr[k].ff, yi = arr[k].ss;
		int s = xi + yi;
	//	cout<<xi<<" "<<yi<<" "<<s<<endl;
		if(op == 1){
			when[k] = i;
			if(s < ch){
				for(int j = i + xi; j < i + s; j++){
					mods[s][j%s]++;
				}
			}
			else{
				for(int j = i;  ; j+=s){
					if(j + xi < MAX){
						dp[j+xi]++;
					}
					else{
						break;
					}
					if(j + s < MAX){
						dp[j+s]--;
					}
					else{
						break;
					}
				}
			}
		}
		else{
			int tim = when[k];
			if(s < ch){
				for(int j = tim + xi; j < tim + s; j++){
					mods[s][j%s]--;
				}
			}
			else{
				if((i- tim) % s >= xi){
					dp[i]--;
				}
				int sv = dp[i];
				for(int j = tim;  ;j+=s){
					if(j + xi < MAX){
						dp[j+xi]--;
					}
					else{
						break;
					}
					if(j + s < MAX){
						dp[j+s]++;
					}
					else{
						break;
					}
				}
				dp[i] = sv;
			}
		}
		int ans = dp[i];
		for(int j = 1; j<ch; j++){
			int cur = i % j;
			ans+=mods[j][cur];
		}
		cout<<ans<<'\n';
	}
}
 

int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}