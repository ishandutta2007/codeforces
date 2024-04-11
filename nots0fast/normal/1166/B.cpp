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


int sy[26];

void deal(){
	int n;
	cin>>n;
	for(int i=2; i<=n ; i++){
		if(!(n%i)){
			int br = i;
			int ik = n/i;
			if(br >= 5 && ik >= 5){
				string vowel = "aeiou";
				string a = "";
				forj(br)
					a+=vowel[j%5];
				forj(ik-1){
					fork(br)
						a += vowel[(k+j+1)%5];
				}
				cout<<a;
				return;
			}
		}
	}
	cout<<-1;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}