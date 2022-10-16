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
#define MAX (int)(pow(10,5) + 10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;
 
 
void deal(){
	ll t;
	cin>>t;
	forl(t){
		int n;
		cin>>n;
		ll definitely = -1;
		vector<bool> SOrN(n+10, 0);
		ll prevVal = -1;
		for(int i = 1; i<=n; i++){
			cout<<"? "<<1<<" "<<n-i<<'\n';
			cout<<i<<'\n';
			for(int j = i+1; j<=n; j++){
				cout<<j<<' ';
			}
			cout<<'\n';
			cout.flush();
			ll f;
			cin>>f;
			if(f!=0){
				// found actual guy
				definitely = i;
				prevVal = f;
				break;
			}
		}
		
		SOrN[definitely] = 1;
		for(int i = definitely+2; i<=n; i++){
			cout<<"? "<<1<<" "<< (  n-i+1  )   <<'\n';
			cout<<definitely<<'\n';
			for(int j = i; j<=n; j++){
				cout<<j<<' ';
			}
			cout<<'\n';
			cout.flush();
			ll f;
			cin>>f;
			if(f != prevVal){
				SOrN[i-1] = 1;
			}
			prevVal = f;
		}
		if(prevVal != 0){
			SOrN[n] = 1;
		}
		
		{
			bool weHaveSeenYes = 0 ;
			vector<int> checking;
			for(int i = 1; i<definitely; i++){
				checking.pb(i);
			}
			while((int)checking.size() != 0){
				if((int)checking.size() == 1 && weHaveSeenYes){
					SOrN[checking[0]] = 1;
					break;
				}
				int sz = checking.size();
				vector<int> l, r;
				for(int i = 0; i<sz; i++){
					if(i<=(sz-1)/2){
						l.pb(checking[i]);
					}
					else{
						r.pb(checking[i]);
					}
				}
				cout<<"? "<<1<<" "<<l.size()<<'\n';
				cout<<definitely<<'\n';
				for(auto& el : l){
					cout<<el<<' ';
				}
				cout<<'\n';
				cout.flush();
				ll f;
				cin>>f;
				if(f!=0){
					weHaveSeenYes = 1;
					checking = l;
				}
				else{
					checking = r;
				}
			}
		}
		
		vector<int> ans;
		for(int i = 1; i<=n; i++){
			if(!SOrN[i]){
				ans.pb(i);
			}
		}
		
		
		cout<<"! "<<ans.size()<<" ";
		for(auto& el : ans){
			cout<<el<<" ";
		}
		cout<<'\n';
		cout.flush();
		
	}
}
 
 
 
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}