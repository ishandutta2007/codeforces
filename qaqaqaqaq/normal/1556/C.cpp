#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int maxn=200007;
const int mod=1e9+7;
const int inf=LLONG_MAX/4;
mt19937 rng(time(NULL)); // don't hack, pls!
int n;
int c[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
	cin>>n;
	rep1(i,n) cin>>c[i];
	int ans=0;
	rep1(i,n){
		if (i%2==0) continue;
		int cur_low=0, cur=0;
		for (int j=i+1;j<=n;++j){
			if (j&1){
				cur+=c[j];
				continue;
			}
			ans+=max(0ll,min(c[i]+cur_low,c[j]-cur+cur_low)+(i+1!=j));
			// cout<<i<<" "<<j<<" "<<ans<<endl;
			cur-=c[j], cur_low=min(cur,cur_low);
		}
	}
	cout<<ans;
	return 0;
}