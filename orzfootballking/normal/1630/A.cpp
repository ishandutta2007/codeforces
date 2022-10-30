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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
void solve(){
	int tn,k;
	cin>>tn>>k;
	int n=0;
	while((1<<n)<tn)n++;
	if(k==(1<<n)-1){
		if(n<=2)cout<<-1<<'\n';
		else {
			int t=(1<<n)-1; 
			cout<<k-1<<' '<<t<<'\n';
			cout<<1<<' '<<3<<'\n';
			cout<<(t^3)<<' '<<0<<'\n';
			rep(i,2,(1<<(n-1))){
				if(i!=3){
					cout<<(t^i)<<' '<<i<<'\n';
				}
			}
		}
	}else if(k){
		int t=(1<<n)-1;
		cout<<k<<' '<<t<<'\n';
		cout<<0<<' '<<(t^k)<<'\n';
		rep(i,1,1<<(n-1)){
			if(i!=k&&i!=(t^k)){
				cout<<(t^i)<<' '<<i<<'\n';
			}
		}
	}else{
		int t=(1<<n)-1;
		rep(i,0,1<<(n-1)){
			cout<<(t^i)<<' '<<i<<'\n';
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve(); 
	RE 0;
}