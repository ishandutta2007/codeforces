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
char c[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n)cin>>c[i];
	int lst=1;
	FOR(i,2,n){
		int t=(i-1)%lst+1;
		if(c[t]>c[i]){
			lst=i;
		}else if(c[t]<c[i]){
			break;
		}
	}
	FOR(i,1,m){
		cout<<c[(i-1)%lst+1];
	}
	RE 0;
}