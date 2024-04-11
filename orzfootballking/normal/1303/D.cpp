#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m,a[100005],l[63];
void solve(){
	cin>>m>>n;
	FILL(l,0);
	rep(i,0,60){
		if((m>>i)&1)l[i]=-1;
	}
	FOR(i,1,n){
		cin>>a[i];
		rep(j,0,30){
			if((a[i]>>j)&1)l[j]++;
		}
	}
//	rep(i,0,60)cout<<l[i]<<' ';
//	cout<<'\n';
	sort(a+1,a+n+1);
	int ans=0;bool anf;
	rep(i,0,60){
		if(l[i]==-1){
			anf=1;
			rep(j,i,60){
				if(l[j]>0){
					anf=0;
					l[j]--;break;
				}
				l[j]++;ans++;
			}
			if(anf){
				cout<<"-1\n";RE;
			}
		}else{
			l[i+1]=l[i+1]+l[i]/2;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}