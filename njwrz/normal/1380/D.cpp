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
int a[200005],b[200005],it[200005];
bool f[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,x,k,y;
	cin>>n>>m>>x>>k>>y;
	FOR(i,1,n){
		cin>>a[i];it[a[i]]=i;
	}
	FOR(i,1,m){
		cin>>b[i];
		if(!it[b[i]]){
			cout<<-1;RE 0;
		}
		f[it[b[i]]]=1;
	}
	FOR(i,2,m){
		if(it[b[i]]<=it[b[i-1]]){
			cout<<-1;RE 0;
		}
	}
	int l=0,maxi=0,ans=0;
	f[n+1]=1;
	FOR(i,1,n+1){
		if(f[i]){
			if(l!=i-1){
				int len=i-l-1;
				if(len<k){
					if(maxi>a[l]&&maxi>a[i]){
						cout<<-1;RE 0;
					}else ans+=len*y;
				}else{
					if(maxi>a[l]&&maxi>a[i]){
						ans+=min((len-k)*y+x,(len%k)*y+(len/k)*x);
					}else ans+=min(len*y,(len%k)*y+(len/k)*x);
				}
				l=i;
			}else l=i;
			maxi=0;
		}else gmax(maxi,a[i]);
	}
	cout<<ans;
	RE 0;
}