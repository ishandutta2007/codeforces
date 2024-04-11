//Think simple yet elegant.
#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll  long long
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define REP(i,n) for(int i=0;i<n;i++)
const ll mod = 1e9+7;
const int BLOCK_SIZE = 200;


ll mul(ll a,ll b){
	if(a>=mod)
		a%=mod;
	if(b>=mod)
		b%=mod;
	ll xt = a*b;
	if(xt>=mod)
		return (xt)%mod;
	return (xt);
}
ll add(ll a,ll b){
	if((a+b)>=mod)
		return (a+b)%mod;
	return (a+b);
}

const int N = 5e5 + 100;
ll C[N][60], x[N], col[60];

void run_case(){
	ll n,i,j,k;

	//<i,j> -> {<j,1>+<j,2>+<j,3>,...............,<j,n>}
	//{<1,1> + <2,1> + .... + <n,1>}-> {1,..|{1,2,...n}}
	cin >> n;
	REP(i,n)
		REP(j,60)
			C[i][j]=0;
	memset(col,0,sizeof(col));

	for(i=0;i<n;i++){
		cin >> x[i];
		ll tt = x[i];
		vector<ll> bin;
		while(tt>0){
			bin.pb(tt%2);
			tt/=2;
		}
		for(j=0;j<bin.size();++j){
			C[i][j] = bin[j];
		}

	}
	for(j=0;j<n;j++)
	for(i=0;i<60;i++){
        col[i] += C[j][i];
	}
	ll ans=0;
		vector<ll> bin;
	for(i=0;i<n;i++){
		ll tt = x[i];
		bin.clear();
		ll O=0,A=0;
		while(tt>0){
			bin.pb(tt%2);
			tt/=2;
		}
		while(bin.size()<60)
			bin.pb(0);
		for(j=0;j<bin.size();++j){
			if(bin[j]==1){
				O = add(O,mul(n,(1LL<<j)));
				A = add(A,mul(col[j],(1LL<<j)));
			}
			else
				O = add(O,mul(col[j],(1LL<<j)));
		}
		ans = add(ans,mul(O,A));
	}
	cout<<ans<<"\n";
}
int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		run_case();
	}
}