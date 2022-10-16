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
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,3) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18)+10;
ll modulo = 10056;



char arr[MAX][MAX];
ll row[MAX];
ll col[MAX];


void deal(){
	ll w,h;
	cin>>w>>h;
	fori(w)
		forj(h)
			cin>>arr[i][j];
	ll s = 0;
	fori(w)
		forj(h){
			ll kd = (arr[i][j] == '*');
			row[i]+=kd, col[j]+=kd, s+=kd;
		}
	ll lz1 = -1;
	fori(w){
		if(row[i] == 2){
			cout<<"NO";
			return;
		}
		if(row[i] >= 3){
			if(lz1!=-1){
				cout<<"NO";
				return;
			}
			lz1 = i;
		}
	}
	if(lz1 == -1){
				cout<<"NO";
				return;
	}
	ll lz2 = -1;
	fori(h){
		if(col[i] == 2){
			cout<<"NO";
			return;
		}
		if(col[i] >= 3){
			if(lz2!=-1){
				cout<<"NO";
				return;
			}
			lz2 = i;
		}
	}
	if(lz2 == -1){
				cout<<"NO";
				return;
	}
	ll s1 = 0;
	ll sv = lz1;
	while(lz1 > -1 && arr[lz1][lz2] == '*')
		--lz1, ++s1;
	lz1 = sv;
	while(lz1 < w && arr[lz1][lz2]=='*')
		++lz1, ++s1;
	lz1 = sv;
	sv = lz2;
	while(lz2 > -1 && arr[lz1][lz2] == '*')
		--lz2, ++s1;
	lz2 = sv;
	while(lz2 < h && arr[lz1][lz2]=='*')
		++lz2, ++s1;
	s1-=3;
	lz2 = sv;
	if( !lz1 || (lz1 == w-1) || !row[lz1-1] || !row[lz1+1] || !lz2 || (lz2==h-1) || !col[lz2-1] || !col[lz2+1] || s1!=s)
		cout<<"NO";
	else	
		cout<<"YES";
}




int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1