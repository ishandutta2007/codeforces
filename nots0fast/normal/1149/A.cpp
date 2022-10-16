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
#define MAX 400100
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

vector<int> primes;
bool cmp[MAX];
int arr[MAX];

void sieve(){
	cmp[0] = cmp[1] = 1;
	for(int i=2; i<MAX; i++)
		if(!cmp[i]){
			primes.pb(i);
			for(int j=2*i; j<MAX; j+=i)
				cmp[j] = 1;
		}
}
vector<int> ans;

void deal(){
	sieve();
	int n;
	cin>>n;
	int ones = 0 , twos = 0;
	fori(n){
		cin>>arr[i];
		(arr[i] == 1 ) ? (++ones) : (++twos);
	}
	int s =0;
	int ind = 0;
	while(ones || twos){
		if(!twos)
			ans.pb(1), --ones;
		else if(!ones)
			ans.pb(2), --twos;
		else{
			if(s+2 <= primes[ind])
				s+=2, --twos, ans.pb(2);
			else
				s+=1, --ones, ans.pb(1);
			if(primes[ind] == s)
				++ind;
		}
	}
	fori(ans.size())
		cout<<ans[i]<<' ';
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}