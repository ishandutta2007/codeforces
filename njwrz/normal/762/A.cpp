/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
using namespace std;
int a[1000005],b[1000005],cnta,cntb;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			a[++cnta]=i;
			if(i*i!=n){
				b[++cntb]=n/i;
			}
		}
	}
	if(k<=cnta){
		cout<<a[k];
	}else if(k<=cnta+cntb){
		cout<<b[cntb-(k-cnta)+1];
	}else cout<<-1;
	RE 0;
}