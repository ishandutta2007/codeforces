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
#define MAX (int)(2*pow(10,5)+10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
const char nl = '\n';
ll modulo = pow(10,9)+7;

int arr[MAX];

bool check(ll a, ll s, ll b, ll num, ll m){ // can the last number be >= b, if we have num terms left
//	cout<<"initial a "<<a<<" initial sum "<<s<<" ";
	fori(num){
		a = s+m;
		s+=a;
	}
//	cout<<"final a "<<a<<endl;
	if(a>=b)
		return 1;
	return 0 ;
}

void deal(){
	ll q;
	cin>>q;
	forl(q){
		ll a,b,m ;
		cin>>a>>b>>m;
		ll lz = -1;
		ll mul = 1;
		if(b == a){	
			cout<<1<<" "<<a<<'\n';
			continue;
		}
		for(ll k = 1; k<51; k++, mul*=2){
			if(b < mul*(a+1) )
				break;
			if(b>=mul*(a+1) && b<=mul*(a+m)){
				lz = k;
				break;
			}
		}
		if(lz==-1)
			cout<<-1<<'\n';
		else{
			cout<<lz+1<<' '<<a<<' ';
			ll s = a;
			fori(lz){
				ll lef = 1, rig = m;
				ll cur = s;
				while(lef < rig){
					ll mid = (lef + rig ) >> 1;
					if(check(cur+mid, s+cur+mid, b, lz-i-1, m))
						rig = mid;
					else
						lef = mid+1;
				}
				cur+=lef;
				cout<<cur<<' ';
				s+=cur;
			}
			cout<<'\n';
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}