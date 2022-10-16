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
#define MAX  (int)(3*pow(10,6) + 10)
#define ld long double
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,9);
ll modulo = pow(10,9)+7;
 
 
ll dx[4] = {-1, 0 , 1, 0};
ll dy[4] = {0, -1, 0 , 1};
string dir = "LURD";
 
void deal(){
	ll t = 1;
//	cin>>t;
	while(t--){
		ll n,a,b,k;
		cin>>n>>a>>b>>k;
		vector<ll> all;
		ll s= 0;
		fori(n){
			ll ed;
			cin>>ed;
			ll qal = ed %( a+b);
			if(qal > 0 && qal<=a){
				++s;
				continue;
			}
			qal-=a;
			if(qal<0){
				qal+=a+b;
			}
			ll nece = qal/a;
		//	cout<<qal<<" "<<a+b<<" "<<a<<endl;
			if(nece * a != qal){
				nece++;
			}
			if(!qal){
				nece = 1;
			}
	//		cout<<"at "<<ed<<" nece "<<nece<<endl;
			all.pb(nece);
		}
		sort(all.begin(),all.end());
		fori(all.size()){
			if(k - all[i] < 0){
				break;
			}
			k-=all[i];
			++s;
		}
		cout<<s<<'\n';
	}
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}