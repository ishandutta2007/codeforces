#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

ll n,k,s,sc;
ll x[100005];
ll c[100005];
bool is[100005];

int main(){
	cin>>n>>k;
	fore(i,0,n)cin>>x[i],s+=x[i];
	fore(i,0,k)cin>>c[i],c[i]--,sc+=x[c[i]],is[c[i]]=true;
	ll r=0;
	fore(i,0,n){
		ll j=(i+1)%n;
		if(!is[i]&&!is[j])r+=x[i]*x[j];
	}
	ll r2=0;
	fore(i,0,n)if(is[i])r+=x[i]*(s-x[i]),r2+=x[i]*(sc-x[i]);
	cout<<r-r2/2<<endl;
	return 0;
}