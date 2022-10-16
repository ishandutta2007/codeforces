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
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  2*pow(10,9);
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,3) + 10)

char arr[MAX][MAX];
ll   ans[MAX][MAX];

void deal(){
	ll n , m;
	cin>>n>>m;
	fori(n)
		forj(m)
			cin>>arr[i][j];
	fori(n){
		forj(m){
			if(!ans[i][j]){
				ll nxt = i+1;
				while(nxt<n && arr[nxt][j] == arr[i][j])
					++nxt;
				for(ll k = i; k<nxt; k++)
					ans[k][j] = nxt - i;
			}
		}
	}
/*	fori(n){
		forj(m)
			cout<<ans[i][j]<<' ';
		cout<<endl;
	}
*/	ll sum = 0;
	for(ll i = 1; i<n; i++){
		char fr = 'Z', sc = 'Z', th = 'Z';
		ll len = -1;
		ll cnt = 0;
		forj(m){
			if(i+ans[i][j] == n || arr[i-1][j] == arr[i][j] ){
				cnt = 0;
				continue;
			}
			if(ans[i+ans[i][j]][j] >= ans[i][j] && ans[i][j] <= ans[i-1][j]){
				if(len == ans[i][j] && fr == arr[i-1][j] && sc == arr[i][j] && th == arr[i+ans[i][j]][j])
					cnt++;
				else
					fr = arr[i-1][j], sc = arr[i][j]  , th = arr[i+ans[i][j]][j], len = ans[i][j], cnt = 1;
				sum+=cnt;
			}
			else
				cnt = 0;
	//		cout<<"after traversing "<<i<<" "<<j<<" sum : "<<sum<<" cnt : "<<cnt<<endl;
		}
	}
	cout<<sum;
}

int main()  
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}