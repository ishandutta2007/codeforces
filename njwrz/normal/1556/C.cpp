#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
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
using namespace std;
int n,a[1005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	ull ans=0;
	FOR(i,1,n)if(i&1){
		int sum=0,t=0;
		FOR(j,i+1,n){
			if(j&1)sum+=a[j];else {
				if(t+1==-sum)ans--;
				sum-=a[j];
				if(-sum>=t){
					ans+=min(a[i],-sum)-t;
					gmax(t,-sum-1);
				}
			}
			if(-sum>a[i])break;
		}
//		cout<<ans<<' ';
	}
	cout<<ans;
	RE 0;
}