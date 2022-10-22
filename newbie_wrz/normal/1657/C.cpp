#include<bits/stdc++.h>
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
int n;
char c[500005];
void solve(){
	int it=1;
	cin>>n;
	FOR(i,1,n)cin>>c[i];
	int ans=0;
	while(it<n){
		if(c[it]=='('){
			it+=2;ans++;
		}else{
			int lst=it;
			it++;
			while(it<=n&&c[it]=='(')it++;
			if(it<=n)it++,ans++;
			else {
				it=lst;break;
			}
		}
	}
	cout<<ans<<' '<<n-it+1<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}