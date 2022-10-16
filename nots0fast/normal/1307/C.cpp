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
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6) + 10)
#define MAX2 (int)(3*pow(10,2) + 4)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;


ll two_letter(string& a, string& b){
	vector<ll> cnt(2,0); // occurence of char1 , total sum
	fori(a.length()){
		if(a[i] == b[1]){
			cnt[1] += cnt[0];
		}
		if(a[i] == b[0]){
			cnt[0]++;
		}
	}
	return cnt[1];
}
 
 
void deal(){
	ll t = 1;
//	cin>>t;
	while(t--){
		string a;
		cin>>a;
		ll mx = 0;
		map<char, ll> all;
		fori(a.length()){
			all[a[i]]++;
		}
		for(auto el : all){
			mx = max(mx, el.ss);
		}
		
		for(char fr = 'a' ; fr  <= 'z'; fr++){
			for(char sc = 'a' ; sc <= 'z' ; sc++){
				string z = "";
				z+=fr;
				z+=sc;
		//		cout<<"two letter for "<<z<<" is "<<two_letter(a,z)<<endl;
				mx = max(mx, two_letter(a, z));
			}
		}
		cout<<mx<<'\n';
	}
	
	
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}