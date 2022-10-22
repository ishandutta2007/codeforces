#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
P<ll,ll> p[100005];
ll n,k,a[100005]; 
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>k;
	ll l;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	l=1;
	ll q=0;
	FOR(i,2,n){
		if(a[i]!=a[i-1]){
			p[++q].F=a[i-1];p[q].S=l;
			l=1;
		}else l++;
	}
	p[++q].F=a[n];p[q].S=l;
	ll s=0,t;
	FOR(i,1,q){
		if(s+p[i].S*n>=k){
			t=i;break;
		}else s=s+p[i].S*n;
	}
	l=p[t].S;
	k=k-s;
	cout<<p[t].F<<' '<<a[k/l+(k%l!=0)];
	return 0;
}