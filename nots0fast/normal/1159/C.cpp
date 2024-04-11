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
#define MAX 300300
#define MAX2 220
#define pb(a) push_back(a)
double eps = 1e-12;
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;
ll arr[MAX];
ll grl[MAX];
void deal(){
	int m,n;
	cin>>m>>n;
	fori(m){
		int ed;
		cin>>ed;
		arr[i] = ed;
	}
	fori(n){
		int ed;
		cin>>ed;
		grl[i] = ed;
	}
	sort(arr, arr+m);
	sort(grl, grl+n);
	if(grl[0] < arr[m-1]){
		cout<<-1;
		return;
	}
	if(grl[0] == arr[m-1]){
		ll s =  0;
		fori(m-1)
			s+=arr[i] * (ll) n;
		fori(n)
			s+=grl[i];
		cout<<s;
	}
	else{
		ll s = 0;
		if(m==1){
			cout<<-1;
			return;
		}
		fori(m-2)
			s+=arr[i] * (ll) n;
		s+=grl[0];
		s+=arr[m-2]*(n-1);
		s+=arr[m-1];
		for(int i=1; i<n; i++)
			s+=grl[i];
		cout<<s;
	}
}



int main(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	deal();
}