#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define lb long double
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
using namespace __gnu_pbds;
int sum0[200005],sum1[200005],a[200005];
int n;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int q;
	cin>>q;
	FOR(i,1,n){
		char c;cin>>c;a[i]=c-'0';
	}
	FOR(i,2,n){
		if(a[i]==a[i-1]){
			if(a[i]){
				sum1[i]++;
			}else sum0[i]++;
		}
		sum1[i]+=sum1[i-1];
		sum0[i]+=sum0[i-1];
	}
	FOR(i,1,q){
		int l,r;
		cin>>l>>r;
		cout<<1+max(sum1[r]-sum1[l],sum0[r]-sum0[l])<<'\n';
	}
	RE 0;
}